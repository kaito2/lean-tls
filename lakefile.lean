import Lake
open Lake DSL

package «lean-tls» where
  leanOptions := #[⟨`autoImplicit, false⟩]

@[default_target]
lean_lib «LeanTLS» where
  srcDir := "."

lean_exe «tests» where
  srcDir := "Tests"
  root := `Main
