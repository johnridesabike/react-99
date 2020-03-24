/* Here's the font stuff, which is surprisingly complicated. */
/* Source: Safari's web inspector. */

module Size = {
  type t =
    | One
    | Two
    | Three
    | Four
    | Five
    | Six
    | Seven;

  let default = Three;

  let fromInt =
    fun
    | 1 => One
    | 2 => Two
    | 3 => Three
    | 4 => Four
    | 5 => Five
    | 6 => Six
    | 7 => Seven
    | x when x < 1 => One
    | _ => Seven;

  let fromString =
    fun
    | "1" => One
    | "2" => Two
    | "3" => Three
    | "4" => Four
    | "5" => Five
    | "6" => Six
    | "7" => Seven
    | x =>
      switch (Belt.Int.fromString(x)) {
      | Some(x) when x < 1 => One
      | Some(_) => Seven
      | None => default
      };

  let toInt =
    fun
    | One => 1
    | Two => 2
    | Three => 3
    | Four => 4
    | Five => 5
    | Six => 6
    | Seven => 7;

  let toPx =
    fun
    | One => "10px"
    | Two => "13px"
    | Three => "16px"
    | Four => "18px"
    | Five => "24px"
    | Six => "32px"
    | Seven => "48px";

  let add = (a, b) => toInt(a) + toInt(b) |> fromInt;

  let parseString = (size, ~base) => {
    switch (Js.String2.charAt(size, 0)) {
    | "+"
    | "-" => add(fromString(size), base)->toPx
    | _ => size->fromString->toPx
    };
  };
};

module Font = {
  type t = {
    color: option(string),
    face: option(string),
    size: option(int),
  };
  let empty = {color: None, face: None, size: None};

  let makeStyle = (defaultProps, ~color, ~face, ~size) => {
    module Style = ReactDOMRe.Style;
    let colorStyle =
      switch (color, defaultProps.color) {
      | (None, None) => Style.make()
      | (Some(color), Some(_))
      | (None, Some(color))
      | (Some(color), None) => Style.make(~color, ())
      };
    let faceStyle =
      switch (face, defaultProps.face) {
      | (None, None) => Style.make()
      | (Some(face), None)
      | (Some(face), Some(_))
      | (None, Some(face)) => Style.make(~fontFamily=face, ())
      };
    let sizeStyle =
      switch (size, defaultProps.size) {
      | (None, None) => Style.make()
      | (None, Some(size)) =>
        Style.make(~fontSize=size->Size.fromInt->Size.toPx, ())
      | (Some(size), None) =>
        Style.make(~fontSize=Size.parseString(size, ~base=Size.default), ())
      | (Some(size), Some(defaultSize)) =>
        Style.make(
          ~fontSize=Size.parseString(size, ~base=Size.fromInt(defaultSize)),
          (),
        )
      };
    colorStyle->Style.combine(faceStyle)->Style.combine(sizeStyle);
  };
};

let context = React.createContext(Font.empty);
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
  let value = Font.{color, face, size};
  <Provider value>
    <div
      style={Font.makeStyle(
        ~color,
        ~face,
        ~size=Option.map(size, string_of_int),
        Font.empty,
      )}>
      children
    </div>
  </Provider>;
};
