{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    cmake
    gnumake
    gcc # Provides the C++ compiler required for C++14
  ];

  shellHook = ''
    echo "Nix environment for prog1 loaded."
    cmake .
    make
  '';
}
