
#git
### BRANCHING STRATEGY

####  Use Separate Branches
• Keep the main or master branch stable.
• Each team member works on their own feature or bugfix branch:

```scss
git checkout -b <branch-name>
```

#### Naming Branches `Use descriptive names`

• feature/\<feature-name> for new features
• bugfix/\<issue-description> for bug fixes
• hotfix/\<urgent-fix> for urgent changes.

### WORK ON YOUR OWN BRANCH

Add and commit changes

- Stages files.

```bash
git add <file-name>  # Add a specific file
git add .            # Add all changes
```

- Commit with a meaningful message.

```bash
git commit -m "Describe what this change does"
```

### KEEP YOUR BRANCH UP TO DATE

- Before pushing changes, pull the latest updates from the main branch to resolve potential conflicts locally:

```bash
git fetch origin
git switch main
git pull origin main
git switch <your-branch-name>
git merge main
```

- Resolve any conflicts, then continue working.

### PUSH YOUR CHANGES

- Push your branch to the remote repository:

```bash
git push origin <your-branch-name>
```

### CREATE PULL REQUEST (PR)

- Open a PR on the repository platform (e.g., GitHub)
- Add a description of the changes and request reviews from team members.
- Address feedback and make changes as needed.

### MERGE YOUR PR

- Once approved, merge your branch into the main branch.
- On the command line, you can merge like this:

```bash
git switch main
git merge <your-branch-name>
```

### CLEAN UP

- After merging, delete the branch

```bash
git branch -d <branch-name>             # Locally
git push origin --delete <branch-name>  # Remotely
```


### CONFLICT RESOLUTION

- If conflicts arise during a merge, Git will pause and mark conflicts in the files. Resolve them manually, then:

```bash
git add <resolved-file>
git commit
```


### BEST PRACTICES

- **Commit Often:** Smaller commits make changes easier to track.
- **Write Clear Messages:** Describe what the change does and why.
- **Pull Regularly:** Avoid large merge conflicts by syncing frequently.
- **Code Reviews:** Ensure quality and catch issues early.
- **Use** `.gitignore` Exclude unnecessary files from the repository.