# ICDE-2024-DB_compression

# DPTC：A Cost-Effective and Decompression-Transparent Compressor for OLTP-Oriented Databases

## Requirements

This library uses SIMD instructions to accelerate the decompression process, so it requires the CPU to support SIMD instructions and currently does not support CPUs with architectures other than x86.

## How to use

An example is shown below.

```C
#include "dptc.h"

char* inpBuf;
char* cmpBuf;
int* inpLens;
int* cmpLens;
int cmpBufSize;
int batchSize;
int* headerLens;

/* compression */
DPTC_compress(inpBuf, cmpBuf, inpLens, cmpLens, cmpBufSize, batchSize, headerLens);

/* decompression */
char* cmpPtr = cmpBuf;
int decLen;
int decBufSize;
char* decBuf;
for (int i = 0; i < batchSize; i++) {
	cmpPtr += headerLens[i];
	decLen = DPTC_decompress(cmpPtr, decBuf, cmpLens[i], decBufSize);
	assert(decLen == inpLens[i]);
	cmpPtr += cmpLens[i];
}
```

Due to the github space limited, the database with row-level compressor need downloads from this [google drive](https://drive.google.com/file/d/1RiZ_o1Emg9D8o0QVmzCmtIMpEPhv_Cyk/view?usp=sharing).


## How to install

You should install PTK tool. And you should create a config file (config.yaml).

```yaml
# config.yaml
global:
    cluster_name: mogdb1
    user: omm
    group: omm
    base_dir: /opt/mogdb
db_servers:
    - host: 127.0.0.1
      db_port: 26000
```

After done, you execute ``ptk install -f config.yaml --pkg ./icde_DBDPTC.tar.gz``.



