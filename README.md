# x86-to-C-interface
S17 MO2-Group 7

Calculation of the Distance between Two Points

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
- **Average Execution Time**:
  - ASM: 0.007767 seconds / 0.002500 seconds
  - C: 0.034800 seconds
- **Total Execution Time**: 
  - ASM: 0.233000 seconds /  0.075000 seconds
  - C: 1.044000 seconds
- **Memory Requirement**: 
  - 7 arrays × 2<sup>20</sup> × 4 bytes = **28 MB**

---

### **Kernel 2**
- **Vector Size**: 16,777,216 elements (2<sup>24</sup>)
- **Average Execution Time**: 
  - ASM: 0.064833 seconds / 0.040933 seconds
  - C: 0.557367 seconds
- **Total Execution Time**: 
  - ASM: 1.945000 seconds / 1.228000 seconds
  - C: 16.721001 seconds
- **Memory Requirement**: 
  - 7 arrays × 2<sup>24</sup> × 4 bytes = **448 MB**

---

### **Kernel 3**
- **Vector Size**: 67,108,864 elements (2<sup>26</sup>)
- **Average Execution Time**: 
  - ASM: 0.432133 seconds / 0.162767 seconds
  - C: 2.411267 seconds
- **Total Execution Time**:
  - ASM: 12.964002 seconds / 4.882999 seconds
  - C: 72.388005 seconds
- **Memory Requirement**: 
  - 7 arrays × 2<sup>26</sup> × 4 bytes = **1792 MB** (≈ 1.75 GB)

---

### Short Observation
ASM executiontimes are faster compared to the equivalent C functions. Each kernel's execution time scales linearly with the size of the vector and the associated memory requirements. The greater the vector size, the longer it takes to execute the kernel. Performance is also PC dependent, with execution times being significantly faster on systems with more powerful processors and sufficient RAM to handle the memory requirements efficiently.

---
![image](https://github.com/user-attachments/assets/bcb000f9-3a56-4cba-88bc-49855437d085)
![image](https://github.com/user-attachments/assets/7535f32c-58dc-43df-aba4-3017abe7c4db)
![image](https://github.com/user-attachments/assets/da2e1b8d-51fc-44f8-8a6b-fb4b0d6ea20c)
![image](https://github.com/user-attachments/assets/a532c3f4-db3a-4a66-b42f-9f5d9158a289)
