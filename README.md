# ActivityTimer
A VST plugin to track your project working duration

![image](https://user-images.githubusercontent.com/61353126/188357153-7f705c02-3e9d-4827-8785-2741799f3a5a.png)

---

## How to use
Just insert the plugin on the output bus. When accepted signal, plugin starts the timer.

## Caution
- Time data will be serialized with your DAW project as plugin arguments. Be careful not to unload the plugin or you will lose this data.
- Max value is 99h99m99s, just for a symmetrical gui. 🤪
