/*
  * corePKCS11 V3.0.1
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
  *
  * http://aws.amazon.com/freertos
  * http://www.FreeRTOS.org
  */
  
 #ifndef _CORE_PKI_UTILS_H_
 #define _CORE_PKI_UTILS_H_
  
 #include <stdint.h>
 #include <stddef.h>
  
 /* @[declare_pkcs11_utils_pkimbedtlssignaturetopkcs11signature] */
 int8_t PKI_mbedTLSSignatureToPkcs11Signature( uint8_t * pxSignaturePKCS,
                                               const uint8_t * pxMbedSignature );
 /* @[declare_pkcs11_utils_pkimbedtlssignaturetopkcs11signature] */
  
  
  
 /* @[declare_pkcs11_utils_pkipkcs11signaturetombedtlssignature] */
 int8_t PKI_pkcs11SignatureTombedTLSSignature( uint8_t * pucSig,
                                               size_t * pxSigLen );
 /* @[declare_pkcs11_utils_pkipkcs11signaturetombedtlssignature] */
 #endif /* ifndef _CORE_PKI_UTILS_H_ */
