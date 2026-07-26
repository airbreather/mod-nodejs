{
	pkgs ? import <nixpkgs> { },
}:
let
	inherit (pkgs)
		symlinkJoin
		libuv
		nodejs-slim_26
		;
in
symlinkJoin {
	name = "mod-nodejs-extradeps";
	paths = [
		libuv
		(nodejs-slim_26.overrideAttrs (nodejs: {
			configureFlags = nodejs.configureFlags ++ [
				"--shared"
				"--shared-temporal_capi"
			];
			doCheck = false; # segfaults, not interested in figuring out why
		})).out
	];
}
