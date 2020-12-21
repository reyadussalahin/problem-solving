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

2. Create a fork of [problem-solving](https://github.com/reyadussalahin/problem-solving) repository.

3. Now, clone the forked repository which is under your account(the possible remote url may be: "https://github.com/{your_user_name}/problem-solving") into your local environment using `git clone <remote-url>` command. TThen, go to `problem-solving` drectory using `cd problem-solving`.

4. Create an `upstream` to the real project(where you'll send pull request) i.e. [https://github.com/reyadussalahin/problem-solving](https://github.com/reyadussalahin/problem-solving) using the command `git remote add upstream https://github.com/reyadussalahin/problem-solving.git`.

5. Fetch all the changes from upstream by using the command `git fetch upstream`.

6. Now create a branch with the name of fixes or changes you are making(means "the name" should reflect what changes/fixes you are making). An example would be - if you are adding a solution for cf 233B problem, then give the branch name "add-cf-233b". Like this `git checkout -b add-cf-233b upstream/main`.

7. Commit your changes in the new branch using `git add <modified-file-name(s)>` and `git commit -m <commit-message>`. Replace `<modified-file-name(s)>` with actual file names and `<commit-message>` with information about changes.

8. This step is optional, but it'll increase the probability of accepting you pull requests. Before pushing your changes, you may want to fetch and merge the changes, those were made in [https://github.com/reyadussalahin/problem-solving](https://github.com/reyadussalahin/problem-solving) while you were working on your feature. Cause, it is possible that your commit may create a merge conflict or some other ugly errors. But you can easily handle those errors(if there are any) by just pulling changes from upstream. If you want to pull changes from upstream, you have to made sure that there are not extra merge commit is occuring, you are not allowed to create a merge commit, cause it'll create problem in merge history, we need to keep merge history as clean as possible. For you there is a proper guide, please take a look at this [article](https://github.com/proven-ways/git-proven-ways#merging-pull-request-without-merge-commits). This will help you deal with the problem. [Note: if this is too much for you, then you don't have to do it. It is an optional step.]

9. Push the branch with changes to your remote repository using the command `git push origin <branch-name>`. Considering step(6) the `<branch-name>` would be replaced by `add-cf-233B`.

10. Go to your remote repository and send a pull request to the real project repository i.e. [https://github.com/reyadussalahin/problem-solving](https://github.com/reyadussalahin/problem-solving).



### Rules for contribution
1. A new branch should contain only one fix, or one solution, or one tutorial, or one tutorial fix etc. **But never more than one.**
2. To do another contribution, please use another branch.
3. Clearly write comments about your pull request, about what you've contributed with specific bullet points.


# If you are new to git and github:
If you are new, then you may use the following resources to get started very quickly with git and github:
 - [Git Tutorials Playlist - YouTube](https://www.youtube.com/playlist?list=PL6gx4Cwl9DGAKWClAD_iKpNC0bGHxGhcx)
 - [The beginner’s guide to contributing to a GitHub project – Rob Allen's DevNotes](https://akrabat.com/the-beginners-guide-to-contributing-to-a-github-project/)
 - [Git docs](https://git-scm.com/docs)
 - Or you may use the command line help *"git help command_name"*. Help would be open in terminal or your default browser.
