/*
 * corePKCS11 v3.4.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
#ifndef _CORE_PKCS11_H_
#define _CORE_PKCS11_H_
 
#include <stdint.h>
 
/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */
 
#ifdef _WIN32
    #pragma pack(push, cryptoki, 1)
#endif
 
#define CK_PTR    *
 
#ifndef NULL_PTR
    #define NULL_PTR    0
#endif
 
#define CK_DEFINE_FUNCTION( returnType, name )             returnType name
 
#define CK_DECLARE_FUNCTION( returnType, name )            returnType name
 
#define CK_DECLARE_FUNCTION_POINTER( returnType, name )    returnType( CK_PTR name )
 
#define CK_CALLBACK_FUNCTION( returnType, name )           returnType( CK_PTR name )
 
#define pkcs11SHA256_DIGEST_LENGTH           32UL
 
#define pkcs11AES_CMAC_SIGNATURE_LENGTH      16UL
 
#define pkcs11ECDSA_P256_SIGNATURE_LENGTH    64UL
 
#define pkcs11ECDSA_P256_KEY_BITS            256UL
 
#define pkcs11RSA_PUBLIC_EXPONENT            { 0x01, 0x00, 0x01 }
 
#define pkcs11RSA_2048_MODULUS_BITS          2048UL
 
#define pkcs11RSA_2048_SIGNATURE_LENGTH      ( pkcs11RSA_2048_MODULUS_BITS / 8UL )
 
#define pkcs11RSA_SIGNATURE_INPUT_LENGTH     51UL
 
#define pkcs11ELLIPTIC_CURVE_NISTP256        "1.2.840.10045.3.1.7"
 
#define pkcs11MAX_LABEL_LENGTH               32UL /* 31 characters + 1 null terminator. */
 
#define pkcs11DER_ENCODED_OID_P256           { 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07 }
 
 
#ifndef pkcs11configIMPORT_PRIVATE_KEYS_SUPPORTED
    #define pkcs11configIMPORT_PRIVATE_KEYS_SUPPORTED    1
#endif
 
#define pkcs11STUFF_APPENDED_TO_RSA_SIG    { 0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x04, 0x20 }
 
/* Bring in the public header. */
 
/* Undefine the macro for Keil Compiler to avoid conflict */
#if defined( __PASTE ) && defined( __CC_ARM )
    /* ARM RCVT stdint.h has a duplicate definition with PKCS #11. */
    #undef __PASTE
#endif
 
#ifdef CreateMutex
    #undef CreateMutex /* This is a workaround because CreateMutex is redefined to CreateMutexW in synchapi.h in windows. :/ */
#endif
 
#include "pkcs11.h"
 
typedef struct PKCS11_CertificateTemplate
{
    CK_ATTRIBUTE xObjectClass;     
    CK_ATTRIBUTE xSubject;         
    CK_ATTRIBUTE xCertificateType; 
    CK_ATTRIBUTE xValue;           
    CK_ATTRIBUTE xLabel;           
    CK_ATTRIBUTE xTokenObject;     
} PKCS11_CertificateTemplate_t;
 
/*------------------------ PKCS #11 wrapper functions -------------------------*/
 
/* @[declare_pkcs11_core_xinitializepkcs11] */
CK_RV xInitializePKCS11( void );
/* @[declare_pkcs11_core_xinitializepkcs11] */
 
/* @[declare_pkcs11_core_xgetslotlist] */
CK_RV xGetSlotList( CK_SLOT_ID ** ppxSlotId,
                    CK_ULONG * pxSlotCount );
/* @[declare_pkcs11_core_xgetslotlist] */
 
/* @[declare_pkcs11_core_xinitializepkcs11session] */
CK_RV xInitializePkcs11Session( CK_SESSION_HANDLE * pxSession );
/* @[declare_pkcs11_core_xinitializepkcs11session] */
 
/* @[declare_pkcs11_core_xinitializepkcs11token] */
CK_RV xInitializePkcs11Token( void );
/* @[declare_pkcs11_core_xinitializepkcs11token] */
 
/* @[declare_pkcs11_core_xfindobjectwithlabelandclass] */
CK_RV xFindObjectWithLabelAndClass( CK_SESSION_HANDLE xSession,
                                    char * pcLabelName,
                                    CK_ULONG ulLabelNameLen,
                                    CK_OBJECT_CLASS xClass,
                                    CK_OBJECT_HANDLE_PTR pxHandle );
/* @[declare_pkcs11_core_xfindobjectwithlabelandclass] */
 
/* @[declare_pkcs11_core_vappendsha256algorithmidentifiersequence] */
CK_RV vAppendSHA256AlgorithmIdentifierSequence( const uint8_t * puc32ByteHashedMessage,
                                                uint8_t * puc51ByteHashOidBuffer );
/* @[declare_pkcs11_core_vappendsha256algorithmidentifiersequence] */
 
#ifdef _WIN32
    #pragma pack(pop, cryptoki)
#endif
 
/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */
 
#endif /* ifndef _CORE_PKCS11_H_ */

