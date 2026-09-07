# Top Navigation Tabs

The application features a top navigation bar (Segmented Control Tabs) that is visible on the main screen but hidden when viewing application details.

## 1. Structure and Variables
The UI (Slint) relies on the `active_tab` integer property to determine the current screen.
The value of the variable represents the active tab:
- `0` : The first tab (Home), displaying the store categories (For You, Browsers, ...).
- `1` : The second tab (Update System), intended for updating the OS and software packages (currently a placeholder).
- `2` : The third tab (Installed Apps), intended for managing currently installed applications (currently a placeholder).

## 2. Styling and Design
The tabs are designed with a modern, Apple-style floating segmented control aesthetic.
- The general background of the tab container uses the `crust` color from the `Catppuccin Mocha` palette.
- The currently active tab stands out with a prominent, colorful background using a glowing `linear-gradient`.
- A glow effect is applied to the active tab using the `drop-shadow-blur` property with a distinct accent color, drawing the user's attention and clearly indicating their current location in the store.
- Switching between tabs smoothly alters the main content displayed below the header area.
