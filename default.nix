{ pkgs, lute }:

pkgs.stdenv.mkDerivation {
  name = "cvec";
  version = "0.1.0";
  src = ./.;

  outputs = [ "out" "dev" ];

  nativeBuildInputs = [
    pkgs.clang-tools
    pkgs.clang
    pkgs.pkg-config
    lute.packages.${pkgs.system}.lute
  ];

  buildPhase = ''
    lute build cvec --release
  '';

  installPhase = ''
    lute install cvec --nix
  '';
}
