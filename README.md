# ![React '99](src/example/header.png)

React '99 is a library of (Reason)React elements that simulate depreciated
HTML elements. Currently it includes:

- \<CENTER>
- \<BLINK>
- \<FONT>
and
- \<BASEFONT>, which provides context with defaults for \<FONT>

[See the docs for usage](https://johnridesa.bike/react-99/).

## Why?

On a whim, I thought it would be funny to recreate 90s HTML with React. Naturally, this project went way further than it deserved.

## Reason & JavaScript

This was written in Reason, but is usable in a JavaScript project too (if you're
sure you want to do that). You'll have to install the peer dependencies
yourself, namely, `bs-platform` and `reason-react`. 

## Run Project

```sh
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open
up `docs/index.html` (**no server needed!**). Then modify whichever `.re` file
in `src` and refresh the page to see the changes.

## Run Project with Server

To run with the webpack development server run `npm run server` and view in the
browser at http://localhost:8000. Running in this environment provides hot
reloading and support for routing; just edit and save the file and the browser
will automatically refresh.

To use a port other than 8000 set the `PORT` environment variable
(`PORT=8080 npm run server`).

## Build for Production

```sh
npm run clean
npm run build
npm run webpack:production
```

This will replace the development artifact `docs/Index.js` for an optimized
version as well as copy `src/exampe/index.html` into `docs/`. You can then
deploy the contents of the `docs` directory (`index.html` and `Index.js`).