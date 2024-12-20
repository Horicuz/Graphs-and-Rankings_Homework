# Graphs and Rankings ~ PROJECT 2: ALGORITHM DESIGN

## Setup ~ COMPLETE
The setup for the project has been completed as follows:

- Created the project folder containing the checker alongside input/output files.  
- Created the Makefile necessary for the checker.

## TASK 1 ~ COMPLETE
- Read the 32 teams from the input file.  
- Simulated matches pairwise, adding winners and losers into two separate queues.  
- Repeated the process of taking two teams from the winners' queue, adding the loser to the losers' queue, and putting the winner back into the winners' queue until all matches were completed.  
- During this process, updated the adjacency matrix of the graph. If team `j` defeats team `i`, there is an edge from vertex `i` to `j`.  
- Printed the adjacency matrix at the end.

## TASK 2 ~ COMPLETE
- After determining all results, all teams were saved in the losers' queue, enabling the winners' queue to be freed.  
- Knowing there are 32 teams, dequeued nodes containing teams from the losers' queue, computed their PageRank (Pr), and displayed it alongside the respective team name (float with 4 decimal places).  
- The required order referred to the order in the losers' queue where `rear = winner` and `front = first loser`.  
- Finally, freed the memory for the adjacency matrix as well.

## Additional Information
- Worked with a single set of nodes, moving them between queues. This caused the `isEmptyQ()` function to become non-functional.
- Each node added to the end of a queue was an already existing node, meaning its `->next` pointer was already occupied. When only one element remained in a queue (`rear = front`), `front->next` was not null but instead pointed to a value. Freeing the `->next` pointer caused memory loss for the node located in the other queue (Losers).
- Implemented several functions such as `CompareTeams 1, 2, 3` and utilized specific queue-related functions.

---

## How to Run

1. **Clone the Repository**
   Clone the project repository to your local machine:
   ```bash
   git clone https://github.com/Horicuz/Graphs-and-Rankings_Homework.git
   ```

2. **Navigate to the Project Directory**
   Change the directory to the project folder:
   ```bash
   cd Graphs-and-Rankings_Homework
   ```

3. **Setup the Project**
   Ensure the project folder contains the input files, output files, and the checker script. Verify that all dependencies are installed and the Makefile is present.

4. **Compile the Code**
   Use the provided Makefile to compile the project:
   ```bash
   make
   ```

5. **Run the Checker**
   Execute the checker script with the appropriate input file:
   ```bash
   ./checker.sh Input/input_file Output/output_file
   ```
   Replace `input_file` and `output_file` with the actual file names provided in the `Input` and `Output` directories.

6. **Inspect Results**
   - The adjacency matrix and computed rankings will be printed or saved as specified in the implementation.
   - Outputs will be compared with expected results using the checker.

7. **Clean Up**
   To remove compiled files and binaries, use:
   ```bash
   make clean
   ```

8. **Additional Notes for Beginners**
   - Ensure you have `gcc` and `make` installed on your system.
   - If you encounter permission issues while running `checker.sh`, grant execute permissions using:
     ```bash
     chmod +x checker.sh
     ```
   - Follow the folder structure as indicated in the repository to avoid file path errors.

---

### Notes
- Ensure input files are formatted correctly as per the problem specifications.
- Modify or extend `CompareTeams` functions and queue operations as needed to address specific requirements or edge cases.
