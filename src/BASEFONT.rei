let defaultFontSize: int;
let getFontSize: int => string;
type font = {
  color: option(string),
  face: option(string),
  size: option(int),
};
let makeFontStyle:
  (
    ~color: option(string),
    ~face: option(string),
    ~size: option(string),
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
[@react.component]
let make:
  (
    ~color: string=?,
    ~face: string=?,
    ~size: int=?,
    ~children: React.element
  ) =>
  React.element;