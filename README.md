# UEPerfHub

UEPerfHub is an Unreal Engine C++ plugin for one-click, unified collection of CPU, GPU, and memory profiling data.

## Current Status

The plugin currently contains its descriptor and Runtime and Editor module startup/shutdown implementations. Capture functionality, editor controls, profiler adapters, and data export are not implemented yet.

The intended targets are the editor, PIE, and profiling-enabled packaged Development/Test builds. The initial modules have been compiled and packaged with Unreal Engine 5.8.2 on Windows; see the validation details below.

## Plugin Structure

```text
UEPerfHub/
├── UEPerfHub.uplugin
├── AGENTS.md
├── README.md
└── Source/
    ├── UEPerfHub/        # Runtime module
    └── UEPerfHubEditor/  # Editor module
```

## Install and Build

1. Place this repository at `<HostProject>/Plugins/UEPerfHub` in an Unreal Engine C++ project.
2. Enable `UEPerfHub` in the host project's `.uproject` `Plugins` array, preserving existing entries: `{ "Name": "UEPerfHub", "Enabled": true }`.
3. Generate or refresh the host project's project files using its Unreal Engine installation.
4. Build the host project's Editor target through its normal Unreal Build Tool workflow, then open the host project.

Build and package runtime targets through the host project's normal workflow. The repository is a plugin, not a standalone Unreal project; use the host project's engine, targets, and toolchain. No engine version is pinned at this stage.

### Standalone Plugin Build (Windows)

Run the following in PowerShell from the repository root. Set `EngineRoot` to your Unreal Engine installation. A compatible Visual Studio C++ toolchain and Windows SDK must be installed.

```powershell
$EngineRoot = 'D:\UnrealEngine\UE_5.8'
$PluginFile = (Resolve-Path -LiteralPath '.\UEPerfHub.uplugin').Path
$PackageDir = Join-Path $env:TEMP ('UEPerfHub-Build-' + [guid]::NewGuid().ToString('N'))

& "$EngineRoot\Engine\Build\BatchFiles\RunUAT.bat" BuildPlugin `
    "-Plugin=$PluginFile" "-Package=$PackageDir" `
    -TargetPlatforms=Win64 -NoDeleteHostProject -Unattended

if ($LASTEXITCODE -ne 0) { throw 'Plugin build failed.' }
Write-Output "Packaged plugin: $PackageDir"
```

Keep the package directory outside the source repository: `BuildPlugin` clears its output directory and copies plugin sources into a temporary host project. This command creates a unique output path and retains that host project for inspection.

### Verified Build

Validated with Unreal Engine **5.8.2**, MSVC **14.50**, and Windows SDK **10.0.22621.0** on Win64:

| Target | Configuration | Result |
| --- | --- | --- |
| UnrealEditor | Development | Runtime and Editor modules compiled and linked |
| UnrealGame | Development | Runtime module compiled |
| UnrealGame | Shipping | Runtime module compiled |
| BuildPlugin | Win64 | Plugin packaging succeeded |

These checks validate compilation and plugin packaging. Editor/PIE execution, packaged-game execution, Test configuration, and profiling data collection have not been validated. The Shipping compile check does not imply support for profiling in Shipping builds.

## Capture Goals

- **Unified control:** start and stop CPU, GPU, and memory collection from one entry point, with results associated with the same capture session.
- **CPU:** support `.utrace` capture and external profilers such as Tracy and Optick through optional adapters.
- **GPU:** collect pass names and actual GPU execution durations.
- **Memory:** collect usage by LLM Track Group.

External profiler dependencies should remain optional. Capture should clearly report unsupported backends, disabled instrumentation, and unavailable measurements. These are development goals, not capabilities of the current module skeleton.
