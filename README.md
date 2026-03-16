# Dotfiles

Personal dotfile configuration managed with [chezmoi](https://www.chezmoi.io/).

## What's Included

- `.bashrc` - Bash shell configuration
- `.bash_profile` - Login shell configuration
- `.gitconfig` - Git configuration
- `.config/nvim` - Neovim configuration (LazyVim)

## Quick Install (New Machine)

```bash
# One-command install
sh -c "$(curl -fsLS get.chezmoi.io)" -- init --apply $GITHUB_USERNAME

# Or with custom repo
./install.sh https://github.com/byvaT/byvaT-dotfile.git
```

## Manual Setup

1. Install chezmoi:
   ```bash
   sh -c "$(curl -fsLS get.chezmoi.io)"
   ```

2. Clone this repository to chezmoi's source directory:
   ```bash
   git clone https://github.com/byvaT/byvaT-dotfile.git ~/.local/share/chezmoi
   ```

3. Apply configurations:
   ```bash
   chezmoi apply
   ```

## Usage

```bash
# Edit a dotfile (always edit through chezmoi)
chezmoi edit ~/.bashrc

# Apply changes
chezmoi apply

# See what would change
chezmoi diff

# Update from source
chezmoi update
```

## Adding New Dotfiles

```bash
# Add a file to chezmoi management
chezmoi add ~/.newconfig

# Or create/edit directly in source
chezmoi edit ~/.bashrc
```

## Machine-Specific Config

Use chezmoi's templating for machine-specific settings. Create files like:
- `~/.bashrc.tmpl` - with `{{ .chezmoi.hostname }}` templates
- Or use `~/.config/chezmoi/chezmoi.toml` for config

## Push Changes

```bash
cd ~/.local/share/chezmoi
git add .
git commit -m "Update dotfiles"
git push
```
