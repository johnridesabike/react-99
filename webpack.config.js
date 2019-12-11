const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const outputDir = path.join(__dirname, "docs/");

const isProd = process.env.NODE_ENV === "production";

module.exports = {
  entry: "./src/example/Index.bs.js",
  mode: isProd ? "production" : "development",
  output: {
    path: outputDir,
    filename: "index.js"
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: "src/example/index.html",
      inject: false
    })
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  },
  module: {
    rules: [
      {
        test: /\.css$/i,
        use: ["style-loader", "css-loader"],
      },
      {
        test: /\.(png|jpe?g|gif|ttf|woff|woff2|eot)$/,
        use: [
          {
            loader: "file-loader",
            options: {
              esModule: false
            },
          },
        ],
      },
      {
        test: /\.m?js$/,
        exclude: /(node_modules|bower_components)/,
        use: {
          loader: "babel-loader",
          options: {
            presets: ["@babel/preset-env"]
          }
        }
      },
      {
        test: /\.(html)$/,
        use: {
          loader: 'html-loader',
          options: {
          }
        }
      }
    ],
  },
};
