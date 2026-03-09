# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

---

### Entry 1
**Date:** 2026-03-04  
**Entry Type:** Bug Fix  
**Task worked on:** Getting the project to compile/run in CLion  
**Issue or decision:** main.cpp was not part of any build target.  
**Error message / symptom (if applicable):** CLion said the file “does not belong to any project target.”  
**What I tried:** Looked around for how to run it and realized it needed CMake setup.  
**Fix / resolution (or final decision):** Configured CMake / created `CMakeLists.txt` so CLion builds `main.cpp`.  
**Commit(s):** My setup commit

---

### Entry 2
**Date:** 2026-03-05  
**Entry Type:** Engineering Decision  
**Task worked on:** Data structure design  
**Issue or decision:** Decided to store the board as a circular linked list with `head`, `tail`, and a `player` pointer.  
**Error message / symptom (if applicable):** N/A  
**What I tried:** Considered using an array/index, but the assignment requires pointer traversal.  
**Fix / resolution (or final decision):** Used `tail->next = head` to make the list circular and moved the player using `next` pointers only.  
**Commit(s):** The commit where I added the class skeleton

---

### Entry 3
**Date:** 2026-03-06  
**Entry Type:** Edge Case / Testing  
**Task worked on:** `addSpace` and board capacity  
**Issue or decision:** Needed to stop at exactly 40 spaces without breaking the list.  
**Error message / symptom (if applicable):** Without a limit, the board could exceed 40 nodes.  
**What I tried:** Inserted normally first, then realized I should block insertion before adding.  
**Fix / resolution (or final decision):** Added a check `if (boardSize == MAX_SPACES) return false;` so no extra nodes are added.  
**Commit(s):**The commit for addSpace/addMany

---

### Entry 4
**Date:** 2026-03-06  
**Entry Type:** Edge Case / Testing  
**Task worked on:** `movePlayer` and passing GO  
**Issue or decision:** Counting GO passes using only traversal logic.  
**Error message / symptom (if applicable):** At first I wasn’t sure where to count “passing GO.”  
**What I tried:** Thought about tracking an index, but that violates the assignment’s pointer-only idea.  
**Fix / resolution (or final decision):** Count a GO pass when the player is on `tail` and moves to `head` (wrap-around point).  
**Commit(s):** The commit for movePlayer/printFromPlayer and clear

---

### Entry 5
**Date:** 2026-03-07  
**Entry Type:** Bug Fix  
**Task worked on:** Memory cleanup (`clear`)  
**Issue or decision:** Circular lists can loop forever when deleting.  
**Error message / symptom (if applicable):** Risk of infinite loop or crash when deleting nodes if the circle stays connected.  
**What I tried:** Tried deleting like a normal list and realized the circle never reaches `nullptr`.  
**Fix / resolution (or final decision):** Broke the circle first with `tail->next = nullptr`, then deleted nodes normally.  
**Commit(s):** The commit for movePlayer/printFromPlayer and clear

---

### Entry 6
**Date:** 2026-03-08  
**Entry Type:** Bug Fix  
**Task worked on:** Advanced features (`removeByName`, `findByColor`)  
**Issue or decision:** Removing nodes needed to handle head/tail/only-node cases and keep the list circular.  
**Error message / symptom (if applicable):** If I didn’t update pointers right, the circle broke or the player pointer could point to deleted memory.  
**What I tried:** Wrote basic removal first, then tested deleting head/tail and found I needed extra checks.  
**Fix / resolution (or final decision):** Tracked `prev` + `cur`, updated `head`/`tail` when needed, moved `player` if it was deleted, and forced `tail->next = head` after removal.  
**Commit(s):** The commit for removeByName/findByColor