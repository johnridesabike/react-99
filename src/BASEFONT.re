module M = Belt.Map.Int;
/* Here's the font stuff, which is surprisingly complicated. */
/* Source: Safari's web inspector. */
let defaultFontSize = 3;
let fontSizes =
  M.fromArray([|
    (1, "10px"),
    (2, "13px"),
    (3, "16px"),
    (4, "18px"),
    (5, "24px"),
    (6, "32px"),
    (7, "48px"),
  |]);
let getFontSize = size =>
  switch (M.get(fontSizes, size)) {
  | Some(size) => size
  | None when size <= 0 => "10px"
  | None => "48px"
  };
let parseSize = (size, baseFontSize) => {
  let sizeIndex =
    switch (size |> Js.String.charAt(0)) {
    | "+"
    | "-" => int_of_string(size) + baseFontSize
    | _ => int_of_string(size)
    };
  let (maxIndex, maxValue) =
    M.maximum(fontSizes)->Belt.Option.getWithDefault((7, "48px"));
  switch (M.get(fontSizes, sizeIndex)) {
  | None when sizeIndex > maxIndex => maxValue
  | None => getFontSize(1)
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
  module Style = ReactDOMRe.Style;
  let colorStyle =
    switch (color, defaultProps |> colorGet) {
    | (None, None) => Style.make()
    | (Some(color), Some(_))
    | (None, Some(color))
    | (Some(color), None) => Style.make(~color, ())
    };
  let faceStyle =
    switch (face, defaultProps |> faceGet) {
    | (None, None) => Style.make()
    | (Some(face), None)
    | (Some(face), Some(_))
    | (None, Some(face)) => Style.make(~fontFamily=face, ())
    };
  let sizeStyle =
    switch (size, defaultProps |> sizeGet) {
    | (None, None) => Style.make()
    | (None, Some(size)) => Style.make(~fontSize=getFontSize(size), ())
    | (Some(size), None) =>
      Style.make(~fontSize=parseSize(size, defaultFontSize), ())
    | (Some(size), Some(defaultSize)) =>
      Style.make(~fontSize=parseSize(size, defaultSize), ())
    };
  colorStyle->Style.combine(faceStyle)->Style.combine(sizeStyle);
};

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
        ~size=Belt.Option.map(size, string_of_int),
        emptyFont,
      )}>
      children
    </div>
  </Provider>;
};