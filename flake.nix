{
  description = "A simple header only c vector library";

  inputs = {
    nixpkgs.url = "nixpkgs/nixos-unstable";
    systems.url = "github:nix-systems/default-linux";

    lute = {
      url = "github:ChangeCaps/lute";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { nixpkgs, systems, lute, ... }: {
    packages = nixpkgs.lib.genAttrs (import systems) (system:
      let pkgs = nixpkgs.legacyPackages.${system}; in rec {
        cvec = import ./. { 
          inherit pkgs; 
          inherit lute;
        };
        default = cvec; 
      }
    );
  };
}
