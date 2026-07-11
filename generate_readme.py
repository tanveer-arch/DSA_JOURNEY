import os
import re
import urllib.parse

# Mapping of folder names to pretty names and icons
FOLDER_CONFIG = {
    "sorting": {
        "name": "Sorting Techniques",
        "icon": "⚡",
        "target": 7
    },
    "array_q's": {
        "name": "Solve Problems on Arrays",
        "icon": "📦",
        "target": 40
    },
    "binarysearch_array": {
        "name": "Binary Search",
        "icon": "🔍",
        "target": 32
    },
    "LL_striverquestions": {
        "name": "Learn LinkedList",
        "icon": "🔗",
        "target": 31
    },
    "recurssion": {
        "name": "Recursion [PatternWise]",
        "icon": "🔄",
        "target": 25
    },
    "strings": {
        "name": "Strings [Basic and Medium]",
        "icon": "🔤",
        "target": 15
    },
    "miscalleaneous": {
        "name": "Miscellaneous / Others",
        "icon": "🌀",
        "target": None
    }
}

FOLDER_ORDER = [
    "sorting",
    "array_q's",
    "binarysearch_array",
    "LL_striverquestions",
    "recurssion",
    "strings",
    "miscalleaneous"
]

def format_problem_name(filename):
    name = os.path.splitext(filename)[0]
    
    # Exclude temporary runner files from formatting
    if name == "tempCodeRunnerFile":
        return None
        
    # Split camelCase and snake_case
    # Insert space before capital letters, replace underscores/hyphens with spaces
    words = re.sub(r'([a-z0-9])([A-Z])', r'\1 \2', name)
    words = re.sub(r'([A-Z]+)([A-Z][a-z])', r'\1 \2', words)
    words = words.replace('_', ' ').replace('-', ' ').replace('.', ' ')
    
    # Common abbreviation replacements
    replacements = {
        "arr": "Array",
        "arrs": "Arrays",
        "ele": "Element",
        "eles": "Elements",
        "subarr": "Subarray",
        "consec": "Consecutive",
        "seq": "Sequence",
        "no": "Number",
        "nos": "Numbers",
        "pos": "Position",
        "diff": "Difficulty",
        "gp": "Group",
        "min": "Minimum",
        "max": "Maximum",
        "bs": "Binary Search",
        "ll": "LinkedList",
        "dll": "Doubly LinkedList",
        "rot": "Rotated",
        "rotarr": "Rotated Array",
        "capi": "Capacity",
        "shippak": "Ship Packages",
        "divithreshold": "Divisor Threshold",
        "mindays": "Minimum Days",
        "bouq": "Bouquets",
        "foccur": "First Occurrence",
        "loccur": "Last Occurrence",
        "lowwrbound": "Lower Bound",
        "kthmissposino": "Kth Missing Positive Number",
        "kokoeatsbanana": "Koko Eats Bananas",
        "upperbound": "Upper Bound",
        "searchinsertpos": "Search Insert Position",
        "howmnytimesarrisrot": "Find Rotation Count of Rotated Array",
        "yintersectioninll": "Intersection Point of Two LinkedLists",
        "add1inll": "Add 1 to a LinkedList",
        "add2nosinll": "Add 2 Numbers in LinkedList",
        "1stnodeofloopinll": "Find 1st Node of Loop in LinkedList",
        "detectllcycle": "Detect Cycle in LinkedList",
        "lengthofcycleinll": "Length of Loop/Cycle in LinkedList"
    }
    
    # Split into list of words to capitalize and replace abbreviations
    word_list = words.split()
    formatted_words = []
    
    for word in word_list:
        lower_word = word.lower()
        if lower_word in replacements:
            formatted_words.append(replacements[lower_word])
        else:
            # Capitalize standard words or uppercase acronyms
            if lower_word in ["ll", "dll", "bs"]:
                formatted_words.append(word.upper())
            else:
                formatted_words.append(word.capitalize())
                
    result = " ".join(formatted_words)
    # Post-processing fixes
    result = result.replace("Linked List", "LinkedList")
    return result

def generate_progress_bar(solved, target):
    if not target:
        return "N/A"
    percentage = min(int((solved / target) * 100), 100)
    bar_length = 10
    filled_length = int(round(bar_length * solved / target))
    filled_length = min(filled_length, bar_length)
    bar = '■' * filled_length + '░' * (bar_length - filled_length)
    return f"`{bar}` {percentage}%"

def main():
    workspace_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Header of README
    readme_content = """# 🚀 Striver's A2Z DSA Prep & Tracker

Welcome to my daily practice repository! Here, I document my solutions to the problems from [Striver's A2Z DSA Sheet](https://takeuforward.org/dsa/strivers-a2z-sheet-learn-dsa-a-to-z).

My main goal is to build a consistent daily coding habit. To keep things transparent and high-quality, every solution contains:
1. **Brute Force Approach** (with Time & Space complexity analysis)
2. **Optimal Approach** (with Intuition & complexity analysis)
3. **Alternative varieties** or related problems when applicable

---

## 📊 Progress Dashboard

| Topic | Progress Bar | Solved / Target |
| :--- | :---: | :---: |
"""

    total_solved = 0
    total_target = 0
    detailed_sections = ""

    for folder_name in FOLDER_ORDER:
        if folder_name not in FOLDER_CONFIG:
            continue
            
        folder_path = os.path.join(workspace_dir, folder_name)
        if not os.path.isdir(folder_path):
            continue
            
        config = FOLDER_CONFIG[folder_name]
        
        # Get list of valid solutions (.cpp files, ignoring temp/runner files)
        solutions = []
        for file in sorted(os.listdir(folder_path)):
            if file.endswith('.cpp') and not file.startswith('tempCodeRunnerFile'):
                solutions.append(file)
                
        solved_count = len(solutions)
        target = config["target"]
        
        total_solved += solved_count
        if target:
            total_target += target
            
        progress_bar = generate_progress_bar(solved_count, target)
        target_str = str(target) if target else "—"
        
        # Add to Dashboard
        readme_content += f"| {config['icon']} [{config['name']}]({urllib.parse.quote(folder_name)}/) | {progress_bar} | **{solved_count}** / {target_str} |\n"
        
        # Build Detailed List
        if solved_count > 0:
            detailed_sections += f"\n### {config['icon']} {config['name']} ({solved_count} solved)\n\n"
            detailed_sections += "| # | Problem Name | Solution File | Link |\n"
            detailed_sections += "| :---: | :--- | :--- | :---: |\n"
            
            for idx, file in enumerate(solutions, 1):
                pretty_name = format_problem_name(file)
                if not pretty_name:
                    continue
                file_url = f"./{urllib.parse.quote(folder_name)}/{urllib.parse.quote(file)}"
                detailed_sections += f"| {idx} | {pretty_name} | `{file}` | [View Code]({file_url}) |\n"

    readme_content += f"\n**🔥 Total Solved:** `{total_solved}` problems overall! \n"
    readme_content += "\n---\n\n## 📚 Solved Problems Index\n"
    readme_content += detailed_sections
    
    readme_content += """
---

## 🛠️ How I Organize My Code

Each file follows a strict structure:
- **Intuition / Explanation**: Notes explaining the thought process behind the solution.
- **Brute Force Implementation**: The first, intuitive solution with $O(N^2)$ or higher complexity.
- **Optimal Implementation**: The best-performing solution with space/time complexity details.

## 🚀 How to Run locally

To run any C++ solution file:
```bash
g++ -O2 -std=c++17 FolderName/FileName.cpp -o solution
./solution
```

---
*Created and maintained automatically by my custom sync scripts.* 🎯
"""

    with open(os.path.join(workspace_dir, "README.md"), "w", encoding="utf-8") as f:
        f.write(readme_content)
    print("README.md generated successfully!")

if __name__ == "__main__":
    main()
