#include "RSAEncryptor.h"

std::string RSAEncryptor::RSAEncrypt(const std::string& plaintext, const CryptoPP::RSA::PublicKey& publicKey)
{
    CryptoPP::AutoSeededRandomPool rng;

    // Convert the plaintext string to Crypto++'s byte representation
    const CryptoPP::byte* plaintextBytes = reinterpret_cast<const CryptoPP::byte*>(plaintext.data());
    size_t plaintextLength = plaintext.length();

    // Create an encryptor using the public key
    CryptoPP::RSAES_OAEP_SHA_Encryptor encryptor(publicKey);

    // Determine the size of the encrypted data
    size_t ciphertextLength = encryptor.CiphertextLength(plaintextLength);

    // Prepare a buffer to hold the encrypted data
    std::vector<CryptoPP::byte> ciphertext(ciphertextLength);

    // Encrypt the plaintext using RSA
    CryptoPP::ArraySink cipherSink(ciphertext.data(), ciphertext.size());
    CryptoPP::ArraySource(plaintextBytes, plaintextLength, true,
        new CryptoPP::PK_EncryptorFilter(rng, encryptor,
            new CryptoPP::Redirector(cipherSink)
        )
    );

    // Convert the encrypted bytes to a string
    std::string encoded(ciphertext.begin(), ciphertext.end());

    // Encode the encrypted data as Base64 for easier representation
    std::string base64Encoded;
    CryptoPP::StringSource(encoded, true,
        new CryptoPP::Base64Encoder(
            new CryptoPP::StringSink(base64Encoded),
            false // Do not append a newline
        )
    );

    return base64Encoded;
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

std::string RSAEncryptor::PublicKeyToString(const CryptoPP::RSA::PublicKey& publicKey)
{
    CryptoPP::ByteQueue queue;
    publicKey.Save(queue);

    std::string serializedKey;
    CryptoPP::Base64Encoder encoder(new CryptoPP::StringSink(serializedKey));
    queue.CopyTo(encoder);
    encoder.MessageEnd();

    return serializedKey;
}

CryptoPP::RSA::PublicKey RSAEncryptor::StringToPublicKey(const std::string& publicKeyString)
{
    CryptoPP::RSA::PublicKey publicKey;

    std::string decodedKey;
    CryptoPP::Base64Decoder decoder(new CryptoPP::StringSink(decodedKey));
    decoder.Put(reinterpret_cast<const CryptoPP::byte*>(publicKeyString.data()), publicKeyString.size());
    decoder.MessageEnd();

    CryptoPP::ByteQueue queue;
    queue.Put(reinterpret_cast<const CryptoPP::byte*>(decodedKey.data()), decodedKey.size());
    queue.MessageEnd();

    publicKey.Load(queue);

    return publicKey;
}
