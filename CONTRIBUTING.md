# Contributing to the Source2Toolkit SDK

Thanks for helping. Fixes to the headers, docs comments, tools and helpers are
all welcome. Contributions go through pull requests from your own fork, against
`main`.

## Branches

| Branch | What it is |
|---|---|
| `main` | What plugins and the core build against. **Open your pull requests against `main`.** |
| `dev` | The maintainer's own working branch. It may be rebased or force-pushed at any time -- do not base work on it and do not open pull requests against it. |

## Workflow

1. **Fork** [Source2Toolkit/source2toolkit-sdk](https://github.com/Source2Toolkit/source2toolkit-sdk)
   on GitHub (the *Fork* button, top right).

2. **Clone your fork** with its submodules, and set up the dependencies:

   ```bash
   git clone --recurse-submodules https://github.com/<you>/source2toolkit-sdk.git
   cd source2toolkit-sdk
   python tools/deps.py init
   ```

3. **Add the upstream remote**, so you can pull in what lands on `main`:

   ```bash
   git remote add upstream https://github.com/Source2Toolkit/source2toolkit-sdk.git
   git fetch upstream
   ```

4. **Make a branch** for your change, from an up-to-date `upstream/main`. One
   branch per pull request:

   ```bash
   git switch -c docs/game-hooks-comments upstream/main
   ```

5. **Commit** your work. Keep commits focused; the first line says what the
   change does, the body says why if it is not obvious.

6. **Stay current** before you open the pull request, and whenever `main` moves
   under you:

   ```bash
   git fetch upstream
   git rebase upstream/main
   git submodule update --init --recursive
   ```

7. **Push** the branch to your fork and **open a pull request** from it into
   `Source2Toolkit/source2toolkit-sdk:main`:

   ```bash
   git push -u origin docs/game-hooks-comments
   ```

   After a rebase, `git push --force-with-lease`.

## Things specific to the SDK

- **Generated files are not edited by hand.** `public/source2toolkit/schema/entity/`
  is written by `tools/schemagen` from the game's schema (a workflow refreshes it
  on every CS2 update); change the generator instead.
- **`vendor/khook` is pinned** to the commit Metamod:Source is built with. Do not
  move it in a pull request -- a plugin built against a different KHook refuses
  to load.
- **Interfaces are versioned.** A change to an existing `IToolkit*` interface's
  layout (a method added, removed, reordered or retyped) is a new revision
  (`IToolkitX002` -> `003`), and the core has to serve both. That needs a matching
  pull request in [source2toolkit](https://github.com/Source2Toolkit/source2toolkit);
  link the two. See [Compatibility](https://www.source2toolkit.net/docs/development/compatibility).
- **No STL or other complex types across a new interface boundary** unless the
  interface already does so.
- **Doc comments** above the `virtual` are what the API reference on the website
  is generated from -- write them for plugin authors.
- **Match the surrounding code**: naming, comment density, formatting.

## Licence

The SDK is GPLv3 with the exceptions in `LICENSE_INFO.txt`. By opening a pull
request you agree that your contribution is licensed under the same terms.

## Questions

Ask in the [Discord](https://discord.gg/4Ck56eDNXj) (`#plugin-developers`) or open
an issue before starting on something large.
