let defaultFontSize: int;
let getFontSize: int => string;
[@bs.deriving abstract]
type font = {
  color: option(string),
  face: option(string),
  size: option(int),
};
let makeFontStyle:
  (
    ~color: option(string),
    ~face: option(string),
    ~size: option(Js.String.t),
    font
  ) =>
  ReactDOMRe.style;
let emptyFont: font;
let context: React.Context.t(font);
module Provider: {
  let makeProps:
    (~value: 'a, ~children: 'b, unit) =>
    {
      .
      "children": 'b,
      "value": 'a,
    };
  let make:
    React.component({
      .
      "children": React.element,
      "value": font,
    });
};
let useContext: unit => font;
[@bs.obj]
external makeProps:
  (
    ~color: 'color=?,
    ~face: 'face=?,
    ~size: 'size=?,
    ~children: 'children,
    ~key: string=?,
    unit
  ) =>
  {
    .
    "children": 'children,
    "color": option('color),
    "face": option('face),
    "size": option('size),
  } =
  "";
let make:
  {
    .
    "children": ReasonReact.reactElement,
    "color": option(string),
    "face": option(string),
    "size": option(int),
  } =>
  React.element;