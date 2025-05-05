# 📦 Non-Cryptographic Hash Algorithms

### A Presentation by Jack Leary
### https://docs.google.com/presentation/d/1nIQ51LyxyyfVvfyt16fQQzJ1GK1FDZ10TzmoubDC5qU/edit?slide=id.p#slide=id.p
---

## 🧠 What Are Non-Cryptographic Hash Algorithms?

Non-cryptographic hash functions:
- Map input data to a numerical value (called a hash)
- Prioritize **speed and distribution**, not security
- Are commonly used in **hash tables**, **databases**, and **networking**

---

## 🔍 Why Are They Interesting?

- Power core data structures like dictionaries and hash maps
- Enable fast lookups in databases and file systems
- Typically much faster than cryptographic hash functions

---

## ⚙️ How Do They Work?

High-level mechanics:
- Break input into **bytes or 4-byte blocks**
- Apply operations like:
  - **XOR**
  - **Bit shifts**
  - **Multiplications**
  - **Rotations**
- Produce uniformly distributed hash values

**Examples:**  
- `MurmurHash3`  
- `xxHash`

---

## 🔢 Example: MurmurHash3

### Input: `"cat"`
1. Convert to bytes:  
   `"c"` = `0x63`, `"a"` = `0x61`, `"t"` = `0x74`, padded with `0x00`  
   → `0x00636174`

2. Multiply by constant:  
   `k = k * 0xcc9e2d51`

3. Rotate left:  
   `k = ROTL32(k, 15)`

4. Multiply again:  
   `k = k * 0x1b873593`

5. Mix into hash state:  
h ^= k
h = ROTL32(h, 13)
h = h * 5 + 0xe6546b64


6. Finalize:
h ^= h >> 16
h *= 0x85ebca6b
h ^= h >> 13
h *= 0xc2b2ae35
h ^= h >> 16

### Result:
- `"cat"` → `0x92d34f2a`
- `"car"` → `0xf18c5f0e` (just 1 letter changed!)

---

## 🧱 Longer Words – Block + Tail Example

**Input:** `"block"`  
- Block 1: `"b", "l", "o", "c"` → `0x636F6C62` (full 4-byte block)
- Tail: `"k"` → `0x6B` (mixed separately into hash)

---

## ⚖️ Tradeoffs

### ✅ Pros:
- **Fast**
- **Great distribution**
- **Minimal memory usage**

### ❌ Cons:
- **Not secure**
- **Susceptible to collisions in adversarial contexts**

---

## 🌍 Real-World Applications

- **Hash tables** (e.g., Python dictionaries)
- **File deduplication** (e.g., `rsync`, Git)
- **Networking** (e.g., DNS caching, packet routing)
- **Game engines** (e.g., loading scenes)

---

## 📚 Sample Test Questions

### ✅ Open-Ended

**Q1:** Why is uniform distribution important in hash tables?  
> To avoid clustering, which degrades performance from O(1) to O(n).

**Q2:** What are some ways systems handle hash collisions?  
> Chaining, open addressing, Robin Hood hashing, and perfect hashing.

---

### ✅ Multiple Choice

**Q1:** Non-cryptographic hash functions prioritize:  
**A.** Data confidentiality  
**B.** Speed and distribution ✅  
**C.** Password protection  
**D.** Key exchange  

**Q2:** What is a hash collision?  
**A.** Two inputs producing the same hash ✅  
**B.** Hash function crashing  
**C.** A secure output from a hash  
**D.** A loss of hashing capability  

**Q3:** In what situation is a non-cryptographic hash a bad choice?  
**A.** Checking file integrity ✅  
**B.** Indexing a database  
**C.** Load balancing  
**D.** Memory allocation

---

## 🧾 In Summary

- Hash functions map data to numerical values.
- Non-cryptographic hash functions are optimized for **speed**, not security.
- They are essential for performance in **data-intensive applications**.

---

### 👋 Thanks for reading!  
This presentation was powered by ChatGPT & crafted by Jack Leary.
