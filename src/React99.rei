module BLINK: {
  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  [@gentype]
  let make:
    {. "children": ReasonReact.reactElement} => ReasonReact.reactElement;
};
module CENTER: {
  [@bs.obj]
  external makeProps:
    (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
    "";
  [@gentype]
  let make:
    {. "children": ReasonReact.reactElement} => ReasonReact.reactElement;
};
let defaultFontSize: int;
let fontSizes: Belt.Map.Int.t(string);
let parseSize: (Js.String.t, int) => string;
type font;
[@bs.obj]
external font:
  (~color: option(string), ~face: option(string), ~size: option(int)) =>
  font =
  "";
let emptyFont: font;
let makeFontStyle:
  (
    ~color: option(string),
    ~face: option(string),
    ~size: option(Js.String.t),
    font
  ) =>
  ReactDOMRe.style;
module BASEFONT: {
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
  [@gentype]
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
  [@gentype]
  let make:
    {
      .
      "children": ReasonReact.reactElement,
      "color": option(string),
      "face": option(string),
      "size": option(int),
    } =>
    React.element;
};
module FONT: {
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
  [@gentype]
  let make:
    {
      .
      "children": ReasonReact.reactElement,
      "color": option(string),
      "face": option(string),
      "size": option(Js.String.t),
    } =>
    ReasonReact.reactElement;
};