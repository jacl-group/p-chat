## Setup git difftool to use meld

```bash
sudo apt install meld
```

https://marcin-chwedczuk.github.io/use-meld-as-git-merge-diff-tool

use kate to edit .gitconfig and add the following sections

```
# ------------------ M E R G E -------------------------
[merge]
    tool = meld

[mergetool "meld"]
    cmd = meld --auto-merge \"$LOCAL\" \"$BASE\" \"$REMOTE\" --output \"$MERGED\" --label \"MERGE (REMOTE BASE MY)\"
    trustExitCode = false

[mergetool]
    # don't ask if we want to skip merge
    prompt = false

    # don't create backup *.orig files
    keepBackup = false

# ------------------ D I F F -------------------------
[diff]
    guitool = meld

[difftool "meld"]
    cmd = meld \"$LOCAL\" \"$REMOTE\" --label \"DIFF (ORIGINAL MY)\"
```