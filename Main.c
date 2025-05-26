#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>        // For using OpenSSL’s SHA-256 hashing functions

int main() {
    char password[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];    // Buffer to store the resulting SHA-256 hash (32 bytes)

    //User input
    printf("Enter a password to hash: ");
    fgets(password, sizeof(password), stdin);    // Read a line of input from the user (up to 255 chars + null terminator)

    // Remove the newline character that fgets includes (if the input was shorter than the buffer)
    password[strcspn(password, "\n")] = 0;

    // Compute the SHA-256 hash of the password
    // (1) cast the password to unsigned char* (required by SHA256)
    // (2) use strlen to get the number of characters in the input
    // (3) store the hash output in the 'hash' buffer
    SHA256((unsigned char*)password, strlen(password), hash);

    // Print the resulting hash as a series of two-digit hexadecimal numbers
    printf("SHA-256 hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]); // %02x: print each byte as two lowercase hex digits, padded with 0 if needed
    }
    printf("\n");
    return 0;
}
