#pragma once
#include <iostream>
#include <string>
#include <rsa.h>
#include <osrng.h>
#include <base64.h>
#include <filters.h>

class RSAEncryptor
{
public:
    static std::string RSAEncrypt(const std::string& plaintext, const CryptoPP::RSA::PublicKey& publicKey);
    static std::string RSADecrypt(const std::string& ciphertext, const CryptoPP::RSA::PrivateKey& privateKey);
    static std::string PublicKeyToString(const CryptoPP::RSA::PublicKey& publicKey);
    static CryptoPP::RSA::PublicKey StringToPublicKey(const std::string& publicKeyString);
};