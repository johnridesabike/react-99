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
    "size": option(Js.String.t),
  } =>
  ReasonReact.reactElement;