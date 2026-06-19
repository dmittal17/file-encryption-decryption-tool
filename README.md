# File Encryption & Decryption Tool 🔐

A C program that encrypts and decrypts files using XOR byte-level encryption.

## Features
- Encrypts any file using a user-provided key
- Decrypts files back to original using the same key
- Works at the byte level using XOR logic
- Symmetric — the same key encrypts and decrypts

## Compilation
```bash
gcc encrypt_decrypt.c -o encrypt_decrypt
```

## Usage
```bash
# To encrypt
./encrypt_decrypt encrypt <input_file> <output_file> <key>

# To decrypt
./encrypt_decrypt decrypt <input_file> <output_file> <key>
```

## Tech Stack
- C language
- Byte-level XOR encryption
