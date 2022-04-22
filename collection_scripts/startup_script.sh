# For running zsh
~/downloads/zsh_install/zsh_binaries/bin/zsh

# For starting dropbox in a session
name="dropbox"
screen="dropbox:0"
tmux new-session -d -s name
tmux send-keys -t $screen "~/downloads/dropbox.py start" Enter
