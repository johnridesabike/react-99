open Belt;
open ReactDOMRe;

[%%raw{|var blinkCss =
  "@keyframes react_99_epic_blink {"
  + "0% {visibility: hidden;}"
  + "50% {visibility: hidden;}"
  + "100% {visibility: visible;}}";
var style = document.createElement('style');
document.head.appendChild(style);
style.type = 'text/css';
style.appendChild(document.createTextNode(blinkCss))|}];
module BLINK = {
  [@react.component]
  let make = (~children) => {
    <div
      style={Style.make(
        ~animation="2s linear infinite react_99_epic_blink",
        (),
      )}>
      children
    </div>;
  };
};

module CENTER = {
  [@react.component]
  let make = (~children) => {
    <div style={Style.make(~textAlign="center", ())}> children </div>;
  };
};

/*
   Here's the font stuff, which is surprisingly complicated.
 */

/* Source: Safari's web inspector. */
let defaultFontSize = 3;
let fontSizes =
  Map.Int.fromArray([|
    (1, "10px"),
    (2, "13px"),
    (3, "16px"),
    (4, "18px"),
    (5, "24px"),
    (6, "32px"),
    (7, "48px"),
  |]);

let parseSize = (size, baseFontSize) => {
  let sizeIndex =
    switch (size |> Js.String.charAt(0)) {
    | "+"
    | "-" => int_of_string(size) + baseFontSize
    | _ => int_of_string(size)
    };
  let (maxIndex, maxValue) =
    fontSizes->Map.Int.maximum->Option.getWithDefault((7, "48px"));
  switch (fontSizes->Map.Int.get(sizeIndex)) {
  | None when sizeIndex > maxIndex => maxValue
  | None => fontSizes->Map.Int.getExn(1)
  | Some(size) => size
  };
};

[@bs.deriving abstract]
type font = {
  color: option(string),
  face: option(string),
  size: option(int),
};
let emptyFont = font(~color=None, ~face=None, ~size=None);

let makeFontStyle = (~color, ~face, ~size, defaultProps) => {
  let colorStyle =
    switch (color, defaultProps->colorGet) {
    | (None, None) => Style.make()
    | (Some(color), Some(_))
    | (None, Some(color))
    | (Some(color), None) => Style.make(~color, ())
    };
  let faceStyle =
    switch (face, defaultProps->faceGet) {
    | (None, None) => Style.make()
    | (Some(face), None)
    | (Some(face), Some(_))
    | (None, Some(face)) => Style.make(~fontFamily=face, ())
    };
  let sizeStyle =
    switch (size, defaultProps->sizeGet) {
    | (None, None) => Style.make()
    | (None, Some(size)) =>
      Style.make(~fontSize=fontSizes->Map.Int.getExn(size), ())
    | (Some(size), None) =>
      Style.make(~fontSize=parseSize(size, defaultFontSize), ())
    | (Some(size), Some(defaultSize)) =>
      Style.make(~fontSize=parseSize(size, defaultSize), ())
    };
  Style.combine(colorStyle, faceStyle)->Style.combine(sizeStyle);
};

module BASEFONT = {
  let context = React.createContext(emptyFont);
  module Provider = {
    let makeProps = (~value, ~children, ()) => {
      "value": value,
      "children": children,
    };
    let make = React.Context.provider(context);
  };

  let useContext = () => {
    React.useContext(context);
  };

  [@react.component]
  let make = (~color=?, ~face=?, ~size=?, ~children) => {
    let value = font(~color, ~face, ~size);
    <Provider value>
      <div
        style={makeFontStyle(
          ~color,
          ~face,
          ~size=size->Option.map(string_of_int),
          emptyFont,
        )}>
        children
      </div>
    </Provider>;
  };
};

module FONT = {
  [@react.component]
  let make = (~color=?, ~face=?, ~size=?, ~children) => {
    <span style={makeFontStyle(~color, ~face, ~size, BASEFONT.useContext())}>
      children
    </span>;
  };
};