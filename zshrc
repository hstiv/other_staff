export PATH="$PATH:$HOME/rvm/bin"
export CLICILIR=1
export LSCOLOR=ExFxCxFxBxrgadabagaacad
export PS1="[%n% ]: "
alias p="pwd | rev | cut -d / -f 1 | rev"
alias c=clear
alias l="ls -la"
alias time="date | cut -d , -f 2 | tr -d ' '"
alias leak="~/Desktop/.link/leak"
clear

# Load Homebrew config script
source $HOME/.brewconfig.zsh
