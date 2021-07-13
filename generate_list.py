import os
import shutil

REPO_NAME = "problem-solving"
SOLUTION_DIR_PREFIXES = ("l1-", "l2-", "l3-", "l4-")
PROBLEM_LIST_DIRNAME = "problem_list"
LEVEL_DIRNAMES = {
    "l1": "level1",
    "l2": "level2",
    "l3": "level3",
    "l4": "level4"
}
OJ_FULLNAME = {
    "cf": "Codeforces",
    "cfg": "Codeforces Gym",
    "cc": "Codechef",
    "timus": "Timus",
    "uva": "UVa",
    "uval": "UVa Live",
    "hr": "Hackerrank",
    "he": "Hackerearth",
    "loj": "LightOJ",
    "spoj": "Spoj",
    "lc": "Leetcode",
    "euler": "Project Euler",
    "atcoder": "Atcoder"
}



def inside_subcategory_directory(dirnames):
    inside_subcat = False
    for dirname in dirnames:
        if dirname.startswith(SOLUTION_DIR_PREFIXES):
            inside_subcat = True
            break
    return inside_subcat


def get_all_level_problem_list_organized_by_level_and_oj(dirnames):
    all_level_problem_list = {}
    for dirname in dirnames:
        if dirname.startswith(SOLUTION_DIR_PREFIXES):
            pieces = dirname.split("-")
            level = pieces[0]
            oj = pieces[1]
            problem_id = "-".join(pieces[2:])
            oj_fullname = OJ_FULLNAME[oj]
            if level not in all_level_problem_list:
                all_level_problem_list[level] = {}
            if oj_fullname not in all_level_problem_list[level]:
                all_level_problem_list[level][oj_fullname] = []
            all_level_problem_list[level][oj_fullname].append((problem_id, dirname))
    return all_level_problem_list



def create_problem_list_directory(dirpath):
    problem_list_dirpath = os.path.join(dirpath, PROBLEM_LIST_DIRNAME)
    if not os.path.exists(problem_list_dirpath):
        os.makedirs(problem_list_dirpath)
    return problem_list_dirpath



def create_level_directory(problem_list_dirpath, level_dirname):
    level_dirpath = os.path.join(problem_list_dirpath, level_dirname)
    if not os.path.exists(level_dirpath):
        os.makedirs(level_dirpath)
    
    # # if any error occurs remove all level dirs
    # if os.path.exists(level_dirpath):
    #     shutil.rmtree(level_dirpath)

    return level_dirpath



def add_problems_to_level_readme(level_dirpath, problem_list):
    print(level_dirpath)
    dirs, level_dirname = os.path.split(level_dirpath)
    dirs, _ = os.path.split(dirs)
    dirs, subcat = os.path.split(dirs)
    dirs, maincat = os.path.split(dirs)
    maincat.strip(".")
    maincat.strip("/")
    # debug start
    print(maincat, subcat, _, level_dirname)
    # debug end
    
    # capitalizing all title parts by word
    maincat_title = " ".join(maincat.split("_")).title()
    subcat_title = " ".join(subcat.split("_")).title()
    level_title = level_dirname.title()

    readme_path = os.path.join(level_dirpath, "README.md")
    with open(readme_path, "w") as readme:
        readme.write(f"## {subcat_title} Problem List: {level_title}\n")
        readme.write("\n\n")
        # sorting problem list by oj name
        problem_list = sorted(problem_list.items(), key=lambda x: x[0])
        # getting subcat path
        subcat_path = os.path.join(maincat, subcat)
        for oj_fullname, problems in problem_list:
            # put oj_fullname as title for listing problems
            readme.write(f"### {oj_fullname}\n")
            
            problems = sorted(problems) # sort problems by id
            for problem_id, solution_dirname in problems:
                # generate the solution path for problem
                solution_dirpath = os.path.join(subcat_path, solution_dirname)
                # change any "-" or "_" with space and beautify
                problem_id = " ".join(problem_id.split("-"))
                problem_id = " ".join(problem_id.split("_"))
                problem_id = problem_id.title()
                # write problem id and link with solution directory
                fixed_solution_dirpath = os.path.join(REPO_NAME, solution_dirpath)
                fixed_solution_dirpath = f"/{fixed_solution_dirpath}"
                readme.write(f"- [{problem_id}]({fixed_solution_dirpath})\n")
            readme.write("\n\n")




# script starts here
for dirpath, dirnames, filenames in os.walk("."):
    if inside_subcategory_directory(dirnames):
        all_level_problem_list = get_all_level_problem_list_organized_by_level_and_oj(dirnames)
        # print(all_level_problem_list)
        problem_list_dirpath = create_problem_list_directory(dirpath)
        for level, level_dirname in LEVEL_DIRNAMES.items():
            if level in all_level_problem_list:
                level_dirpath = create_level_directory(problem_list_dirpath, level_dirname)
                add_problems_to_level_readme(level_dirpath, all_level_problem_list[level])
