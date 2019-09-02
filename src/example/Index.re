%raw
{|import "prismjs"|};
%raw
{|import "firacode/distr/fira_code.css"|};
%raw
{|import "./index.css"|};

module SuperCoolHeader = {
  [@react.component]
  let make = () => {
    <CENTER>
      <BLINK>
        <FONT color="red" size="7"> {React.string("Get up and slam!")} </FONT>
      </BLINK>
    </CENTER>;
  };
};

module MindBlowingEffect = {
  [@react.component]
  let make = () => {
    <BASEFONT color="green" size=5 face="comic sans ms">
      <CENTER>
        <marquee>
          {React.string("And welcome to the ")}
          <FONT size="+1"> {React.string("Jam.")} </FONT>
        </marquee>
      </CENTER>
    </BASEFONT>;
  };
};

ReactDOMRe.renderToElementWithId(<SuperCoolHeader />, "reasonExample1");

ReactDOMRe.renderToElementWithId(<MindBlowingEffect />, "reasonExample2");