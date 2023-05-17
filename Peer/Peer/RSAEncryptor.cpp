#include "RSAEncryptor.h"

std::string RSAEncryptor::RSAEncrypt(const std::string& plaintext, const CryptoPP::RSA::PublicKey& publicKey)
{
    CryptoPP::AutoSeededRandomPool rng;
    std::string ciphertext;

    CryptoPP::RSAES_PKCS1v15_Encryptor encryptor(publicKey);
    CryptoPP::StringSource(plaintext, true,
        new CryptoPP::PK_EncryptorFilter(rng, encryptor,
            new CryptoPP::StringSink(ciphertext)
        )
    );

    // Return Base64-encoded ciphertext
    std::string encodedCiphertext;
    CryptoPP::StringSource(ciphertext, true,
        new CryptoPP::Base64Encoder(
            new CryptoPP::StringSink(encodedCiphertext),
            false /*insertLineBreaks*/,
            64 /*lineLength*/
        )
    );

    return encodedCiphertext;
}

std::string RSAEncryptor::RSADecrypt(const std::string& ciphertext, const CryptoPP::RSA::PrivateKey& privateKey)
{
    CryptoPP::AutoSeededRandomPool rng;

    // Decode the ciphertext from Base64
    std::string decoded;
    CryptoPP::StringSource(ciphertext, true,
        new CryptoPP::Base64Decoder(
            new CryptoPP::StringSink(decoded)
        )
    );

    // Convert the decoded ciphertext to Crypto++'s byte representation
    const CryptoPP::byte* ciphertextBytes = reinterpret_cast<const CryptoPP::byte*>(decoded.data());
    size_t ciphertextLength = decoded.length();

    // Create a decryptor using the private key
    CryptoPP::RSAES_OAEP_SHA_Decryptor decryptor(privateKey);

    // Determine the size of the decrypted data
    size_t plaintextLength = decryptor.MaxPlaintextLength(ciphertextLength);

    // Prepare a buffer to hold the decrypted data
    std::vector<CryptoPP::byte> decryptedBuffer(plaintextLength);

    // Decrypt the ciphertext using RSA
    CryptoPP::ArraySink plainSink(decryptedBuffer.data(), decryptedBuffer.size());
    CryptoPP::ArraySource(ciphertextBytes, ciphertextLength, true,
        new CryptoPP::PK_DecryptorFilter(rng, decryptor,
            new CryptoPP::Redirector(plainSink)
        )
    );

    // Copy the decrypted data back to a string
    std::string plaintext(decryptedBuffer.begin(), decryptedBuffer.end());

    return plaintext;
}

byte* RSAEncryptor::PublicKeyToString(const CryptoPP::RSA::PublicKey& publicKey)
{
    CryptoPP::ByteQueue byteQueue;

    // Save the public key to the byte queue
    publicKey.Save(byteQueue);

    // Retrieve the byte queue as a string or byte array
    size_t size = byteQueue.CurrentSize();
    byte* buffer = new byte[size];
    byteQueue.Get(buffer, size);


    std::string convertedString;

    // Convert byte array to char* using Crypto++
    CryptoPP::ArraySource(buffer, size, true,
        new CryptoPP::HexEncoder(
            new CryptoPP::StringSink(convertedString)
        )
    );

    byte* byteArray = new byte[size];

    // Convert the hex-encoded string to byte array using Crypto++
    CryptoPP::StringSource(convertedString, true,
        new CryptoPP::HexDecoder(
            new CryptoPP::ArraySink(byteArray, size)
        )
    );


    return byteArray;
}

CryptoPP::RSA::PublicKey RSAEncryptor::StringToPublicKey(const std::string& publicKeyString)
{
    CryptoPP::RSA::PublicKey publicKey;

    CryptoPP::ByteQueue queue;
    CryptoPP::StringSource stringSource(publicKeyString, true);
    stringSource.TransferTo(queue);
    queue.MessageEnd();

    publicKey.BERDecodePublicKey(queue, false /* raw material */, queue.MaxRetrievable());

    return publicKey;
}
