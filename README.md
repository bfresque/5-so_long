
# **So Long: A Simple 2D Game**

## **Project Description**
The goal of this project is to create a simple 2D game using **MiniLibX**. You will work with textures, sprites, and basic gameplay mechanics such as movement, collision detection, and map parsing.

---

## **Mandatory Part**

### **Program Requirements**
1. **Program Name**: `so_long`
2. **Files to Submit**:
   - `Makefile`  
   - Header files (`*.h`)  
   - Source files (`*.c`)  
   - Sample maps (`*.ber`)  
   - Textures for your game.

3. **External Functions Allowed**:
   - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`  
   - **MiniLibX** functions  
   - **Mathematical library** (`-lm` flag)  
   - `ft_printf` or any equivalent function coded by you.

4. **Compilation**:
   - Use the following flags:
     ```bash
     -Wall -Wextra -Werror
     ```
   - The Makefile must contain the rules: `NAME`, `all`, `clean`, `fclean`, and `re`.  
   - The program **must not relink**.

### **Gameplay**:
1. **Objective**:
   - The player must collect all items on the map and exit through the designated point.

2. **Movement**:
   - Use the `W`, `A`, `S`, and `D` keys to move the character:  
     - `W` : Move up  
     - `A` : Move left  
     - `S` : Move down  
     - `D` : Move right  

3. **Game Mechanics**:
   - The player cannot move through walls.  
   - Every movement must be counted and displayed in the terminal.  
   - A **2D top-down view** must be used.

4. **Game Exit**:
   - The player exits after collecting all items.

### **Graphical Management**:
1. Display the game in a window using **MiniLibX**.
2. The program must handle the following events:
   - Pressing `ESC` must close the game window.  
   - Clicking the close button (`X`) must close the game window.  
3. Window behavior (e.g., minimizing, resizing) must remain smooth.

---

## **Map Configuration**

1. **Map File**:
   - The map is provided as a `.ber` file and must contain the following characters:
     - `0` : Empty space  
     - `1` : Wall  
     - `C` : Collectible item  
     - `E` : Exit  
     - `P` : Player starting position  

2. **Example Map**:
   ```
   1111111111111
   10010000000C1
   1000011111001
   1P0011E000001
   1111111111111
   ```

3. **Map Rules**:
   - The map must contain **one player start position (P)**, **at least one item (C)**, and **one exit (E)**.  
   - The map must be rectangular.  
   - The map must be surrounded by walls (`1`).  
   - The program must verify that there is a valid path from the player to the exit.

4. **Error Handling**:
   - If the map is invalid, the program must print an error message and exit gracefully:
     ```
     Error


## **How to Run the Project**

1. **Compile the Program**:
   ```bash
   make
   ```

2. **Run the Game**:
   Provide a valid `.ber` map file as an argument:
   ```bash
   ./so_long maps/map.ber
   ```

3. **Clean Compiled Files**:
   - `make clean` : Removes object files.  
   - `make fclean` : Removes object files and the executable.  

4. **Recompile**:
   ```bash
   make re
   ```

---

## **Testing**

### **Example Test Map**:
Save this content as `example.ber`:
```
111111
1P00E1
1C0011
111111
```

### **Run the Game**:
```bash
./so_long example.ber
```

### **Expected Behavior**:
- The game window opens and displays the map.  
- Use `W`, `A`, `S`, and `D` to move the player.  
- Collect all items and exit through the `E`.  
- The number of movements is displayed in the terminal.  

---

### 🚀🚀🚀