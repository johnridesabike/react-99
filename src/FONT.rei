[@react.component]
let make:
  (
    ~color: string=?,
    ~face: string=?,
    ~size: string=?,
    ~children: React.element
  ) =>
  React.element;