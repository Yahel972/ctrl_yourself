#pragma once
#include <iostream>
#include <string>
#include <rsa.h>
#include <osrng.h>
#include <base64.h>
#include <filters.h>
#include <files.h>
#include <hex.h>
#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include "KeyLogger.h"
#include "MouseLogger.h"
#include "ScreenCapture.h"
#include <exception>
#include <iostream>
#include <vector>
#include <thread>
#include "MouseMessage.h"
#include "MousePosMessage.h"
#include "KeyboardMessage.h"
#include <regex>
#include <iphlpapi.h>
#include <winsock2.h>

class RSAEncryptor
{
public:
    static std::string RSAEncrypt(const std::string& plaintext, const CryptoPP::RSA::PublicKey& publicKey);
    static std::string RSADecrypt(const std::string& ciphertext, const CryptoPP::RSA::PrivateKey& privateKey);
    static byte* PublicKeyToString(const CryptoPP::RSA::PublicKey& publicKey);
    static CryptoPP::RSA::PublicKey StringToPublicKey(const std::string& publicKeyString);
};