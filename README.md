# x86-to-C-interface
S17 MO2-Group 7
Euclidean Distance of Two Vectors

## Performance of the Kernels
### **PC SPECS**
- Casey's
  - Processor	Intel(R) Core(TM) i5-10210U CPU @ 1.60GHz   2.10 GHz
  - Installed RAM	8.00 GB (7.60 GB usable)
- Germaine's
  - Processor	Intel(R) Core(TM) i7-8700 CPU @ 3.20GHz   3.19 GHz
  - Installed RAM	16.0 GB (15.9 GB usable)
 
*The execution times listed in the kernels are based on [Casey's runs / Germaine's runs].*
---

### **Kernel 1**
- **Vector Size**: 1,048,576 elements (2<sup>20</sup>)
- **Average Execution Time**: 0.007767 seconds / 0.002500 seconds
- **Total Execution Time**: 0.233000 seconds /  0.075000 seconds
- **Memory Requirement**: 
  - 7 arrays × 2<sup>20</sup> × 4 bytes = **28 MB**

---

### **Kernel 2**
- **Vector Size**: 16,777,216 elements (2<sup>24</sup>)
- **Average Execution Time**: 0.064833 seconds / 0.040933 seconds
- **Total Execution Time**: 1.945000 seconds / 1.228000 seconds
- **Memory Requirement**: 
  - 7 arrays × 2<sup>24</sup> × 4 bytes = **448 MB**

---

### **Kernel 3**
- **Vector Size**: 67,108,864 elements (2<sup>26</sup>)
- **Average Execution Time**: 0.432133 seconds / 0.162767 seconds
- **Total Execution Time**: 12.964002 seconds / 4.882999 seconds
- **Memory Requirement**: 
  - 7 arrays × 2<sup>26</sup> × 4 bytes = **1792 MB** (≈ 1.75 GB)

---

### Short Observation
Each kernel's execution time scales linearly with the size of the vector and the associated memory requirements. The greater the vector size, the longer it takes to execute the kernel. Performance is also PC dependent, with execution times being significantly faster on systems with more powerful processors and sufficient RAM to handle the memory requirements efficiently.

---

![image](https://github.com/user-attachments/assets/92b22e00-f7a1-40bf-9b2d-16dcf6cac19d)

![image](https://github.com/user-attachments/assets/e01ca916-e10e-4034-841e-99c6330e9897)

![image](https://github.com/user-attachments/assets/4d115625-8d38-4c55-9a44-467000072e70)
