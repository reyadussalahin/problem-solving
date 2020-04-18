# Contributing
Before read this file please read the [README.md](README.md) file.

<!--
You can contribute to this repository by:
- adding solutions to problems
- writing tutorials for those solutions
- writing tutorials for different problem solving techniques related to data structures and algorithms.
 -->

### Process of Contribution
The process to contribute this repository may be summarized as follows:
1. You must have a github account to contribute to this project. You if don't have one, then please create one.
2. Create a fork of [problem_solving](https://github.com/reyadussalahin/problem_solving) repository.
3. Now, clone the forked repository which is under your account(the possible url may be - "https://github.com/{your_user_name}/problem_solving") into your local environment.
4. Create an "upstream" to the main project i.e. [problem_solving](https://github.com/reyadussalahin/problem_solving) using the command ``` git remote add upstream https://github.com/reyadussalahin/problem_solving.git ```.
5. Pull all the changes from root project dev branch by using the command ```git pull upstream dev``` and merge the changes to your remote dev by using ```git push origin dev```.
6. Now create a branch with the name of fixes or changes you are making(means "the name" should reflect what changes/fixes you are making). An example would be - if you are adding a solution for cf 233B problem, then give the branch name "add_cf233b". Like this ``` git checkout -b add_cf233b ```
7. Commit your changes in the new branch using ``` git add file_name(s) ``` and ``` git commit -m commit_message ```. Replace file_name(s) with actual file names(you may also use absolute file path) and commit_message with information about changes.
8. Push the branch with changes to your remote repository using the command ``` git push origin branch_name ```. Considering step(7) the "branch_name" would be replaced by "add_cf233B".
9. Go to your remote repository and send a pull request to the root project repository.
10. Always perform step(5) before creating any new branch for contribution and always try to pull the latest changes from the root repository's dev branch before commit and pull request.


### Rules for contribution
1. A new branch should contain only one fix, or one solution, or one tutorial, or one tutorial fix etc. **But never more than one.**
2. To do another contribution, please use another branch.
3. Make your dev branch always up to date with the root projects dev branch.
4. Please, never contribute to the master branch. It would never be accepted.
5. And clearly write in the comment of pull request what you've contributed with specific points.


# If you are new to git and github:
If you are new, then you may use the following resources to get started very quickly with git and github:
 - [Git Tutorials Playlist - YouTube](https://www.youtube.com/playlist?list=PL6gx4Cwl9DGAKWClAD_iKpNC0bGHxGhcx)
 - [The beginner’s guide to contributing to a GitHub project – Rob Allen's DevNotes](https://akrabat.com/the-beginners-guide-to-contributing-to-a-github-project/)
 - [Git docs](https://git-scm.com/docs)
 - Or you may use the command line help *"git help command_name"*. Help would be open in terminal or your default browser.
