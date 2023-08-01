int /* the number of bytes written into buffer 'dest' */
DPTC_compress(
    const char* source, /* input tuples */
    char* dest, /* memory buffer to put the compressed tuples(must be already allocated) */
    int* inputSize, /* byte-lengths of the input tuples */
    int* outputSize, /* byte-lengths of the compressed tuples */
    int maxOutputSize, /* size of buffer 'dest' */
    int batchSize, /* number of tuples in batch to compress */
    int* headerLen /* byte-lengths of tuple headers */
);

int /* the number of bytes decompressed into buffer 'dest'(<= maxDecompressedSize) */
DPTC_decompress(
    const char* source, /* the conpressed tuple */
    char* dest, /* memory buffer to put the decompressed tuple */
    int compressedSize, /* byte-length of the compressed tuple */
    int maxDecompressedSize /* the size of buffer 'dest' */
);