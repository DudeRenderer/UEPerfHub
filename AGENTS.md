# UEPerfHub

UEPerfHub is an Unreal Engine C++ plugin for one-click, unified collection of CPU, GPU, and memory profiling data. It targets the editor, PIE, and profiling-enabled packaged Development/Test builds.

## Project Structure

- `UEPerfHub.uplugin` declares the plugin and its modules.
- `Source/UEPerfHub` is the Runtime module. Put capture coordination and collectors here.
- `Source/UEPerfHubEditor` is the Editor module. Put editor integration and controls here; keep editor dependencies out of the Runtime module.
- `README.md` documents installation, verified build instructions, current capabilities, and capture goals. Update it when behavior or setup changes.

## Capture Requirements

- Provide one entry point to coordinate CPU, GPU, and memory collection and associate the results with the same capture session.
- Editor controls and runtime console commands must use the same runtime capture API. Keep one active session by default and place its outputs under the host project's `Saved/UEPerfHub/<SessionId>/` directory.
- Support CPU capture using `.utrace` and external profilers such as Tracy and Optick through optional adapters. Keep profiler-specific dependencies isolated so the plugin can build without those SDKs.
- Select one CPU backend per session by default; concurrent CPU backends are not an initial requirement.
- Collect GPU pass names and actual GPU execution durations. Do not substitute CPU submission time for GPU time.
- Collect memory usage by LLM Track Group. Verify the available engine data source and document the recorded units and sampling behavior.
- Report unavailable backends, disabled instrumentation, and missing data explicitly. Do not report missing measurements as zero or silently substitute another backend.

## Implementation

- Use English for code identifiers, comments, documentation, commit messages, logs, and user-facing text. Follow Unreal Engine C++ naming and module conventions.
- Inspect the target engine headers and existing plugin code before selecting APIs. Keep engine-version assumptions explicit; do not invent build commands or depend on unverified APIs.
- Declare module dependencies in the appropriate `Build.cs`. Guard editor-only code and optional profiler integrations so packaged builds do not acquire editor or unavailable SDK dependencies.
- Respect engine thread ownership and asynchronous GPU readback requirements. Avoid blocking the game or render thread for capture processing or file output.
- Make capture start/stop and cleanup safe across repeated sessions, PIE teardown, and module shutdown. Release owned resources and unregister callbacks before their owners are destroyed.
- Preserve native profiler outputs where needed. Do not claim precise cross-profiler time alignment without an implemented and verified synchronization mechanism.

## Validation

- Use the verified `BuildPlugin` command in `README.md` for standalone build validation, or build through a host Unreal project using its engine and Unreal Build Tool. Record the engine version and targets actually validated.
- For capture changes, exercise repeated start/stop, PIE teardown, unavailable instrumentation, and operation without external profiler SDKs. Validate packaged Development/Test behavior when the change affects runtime capture.
- Check recorded GPU durations and memory values against the source profiler or engine tooling. Add focused tests for coordination and error handling when those components exist.
- Distinguish implemented capabilities from planned work in documentation and change summaries. Report checks that could not be run and why.
