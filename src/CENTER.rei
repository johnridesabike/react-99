[@bs.obj]
external makeProps:
  (~children: 'children, ~key: string=?, unit) => {. "children": 'children} =
  "";
let make:
  {. "children": ReasonReact.reactElement} => ReasonReact.reactElement;