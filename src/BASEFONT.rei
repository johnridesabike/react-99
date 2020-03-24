module Size: {
  type t =
    | One
    | Two
    | Three
    | Four
    | Five
    | Six
    | Seven;

  let default: t;

  let fromInt: int => t;

  let parseString: (string, ~base: t) => string;
};

module Font: {
  type t = {
    color: option(string),
    face: option(string),
    size: option(int),
  };

  let makeStyle:
    (
      t,
      ~color: option(string),
      ~face: option(string),
      ~size: option(string)
    ) =>
    ReactDOMRe.style;

  let empty: t;
};

let context: React.Context.t(Font.t);

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
      "value": Font.t,
    });
};

let useContext: unit => Font.t;

[@react.component]
let make:
  (
    ~color: string=?,
    ~face: string=?,
    ~size: int=?,
    ~children: React.element
  ) =>
  React.element;
