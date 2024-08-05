{ pkgs, lute }:

pkgs.stdenv.mkDerivation {
  name = "hjaltes-widgets";
  version = "0.1.0";

  src = ./.;

  nativeBuildInputs = [
    pkgs.clang-tools
    pkgs.clang
    lute.packages.${pkgs.system}.lute
  ];
}
