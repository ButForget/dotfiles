#!/bin/bash
# Install chezmoi and apply dotfiles on a new machine

set -e

# Install chezmoi
sh -c "$(curl -fsLS get.chezmoi.io)" -- bin --destination="$HOME/.local/bin"

# Add to PATH
export PATH="$HOME/.local/bin:$PATH"

# Clone dotfiles repo (replace with your repo URL)
# Example: git clone https://github.com/yourusername/dotfiles.git ~/.local/share/chezmoi
REPO_URL="${1:-https://github.com/ButForget/dotfiles.git}"

# If repo already exists, use it; otherwise clone
if [ -d "$HOME/.local/share/chezmoi" ]; then
  echo "Dotfiles already exist, pulling latest..."
  cd "$HOME/.local/share/chezmoi" && git pull
else
  echo "Cloning dotfiles from $REPO_URL..."
  git clone "$REPO_URL" "$HOME/.local/share/chezmoi"
fi

# Apply dotfiles
chezmoi apply

echo "Dotfiles installed successfully!"
