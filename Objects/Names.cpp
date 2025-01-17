#pragma once

const char* TOPOLOGY_ITEM_NAMES[] =
{
	"Undefined",
	"PointList",
	"LineList",
	"LineStrip",
	"TriangleList",
	"TriangleStrip",
	"LineListAdjecent",
	"LineStripAdjecent",
	"TriangleListAdjecent",
	"TriangleStripAdjecent"
};

const char* SHADER_TYPE_NAMES[] =
{
	"Pixel",
	"Vertex"
};

const char* FORMAT_NAMES[] = {
	"UNKNOWN\0",
	"R32G32B32A32_TYPELESS\0",
	"R32G32B32A32_FLOAT\0",
	"R32G32B32A32_UINT\0",
	"R32G32B32A32_SINT\0",
	"R32G32B32_TYPELESS\0",
	"R32G32B32_FLOAT\0",
	"R32G32B32_UINT\0",
	"R32G32B32_SINT\0",
	"R16G16B16A16_TYPELESS\0",
	"R16G16B16A16_FLOAT\0",
	"R16G16B16A16_UNORM\0",
	"R16G16B16A16_UINT\0",
	"R16G16B16A16_SNORM\0",
	"R16G16B16A16_SINT\0",
	"R32G32_TYPELESS\0",
	"R32G32_FLOAT\0",
	"R32G32_UINT\0",
	"R32G32_SINT\0",
	"R32G8X24_TYPELESS\0",
	"D32_FLOAT_S8X24_UINT\0",
	"R32_FLOAT_X8X24_TYPELESS\0",
	"X32_TYPELESS_G8X24_UINT\0",
	"R10G10B10A2_TYPELESS\0",
	"R10G10B10A2_UNORM\0",
	"R10G10B10A2_UINT\0",
	"R11G11B10_FLOAT\0",
	"R8G8B8A8_TYPELESS\0",
	"R8G8B8A8_UNORM\0",
	"R8G8B8A8_UNORM_SRGB\0",
	"R8G8B8A8_UINT\0",
	"R8G8B8A8_SNORM\0",
	"R8G8B8A8_SINT\0",
	"R16G16_TYPELESS\0",
	"R16G16_FLOAT\0",
	"R16G16_UNORM\0",
	"R16G16_UINT\0",
	"R16G16_SNORM\0",
	"R16G16_SINT\0",
	"R32_TYPELESS\0",
	"D32_FLOAT\0",
	"R32_FLOAT\0",
	"R32_UINT\0",
	"R32_SINT\0",
	"R24G8_TYPELESS\0",
	"D24_UNORM_S8_UINT\0",
	"R24_UNORM_X8_TYPELESS\0",
	"X24_TYPELESS_G8_UINT\0",
	"R8G8_TYPELESS\0",
	"R8G8_UNORM\0",
	"R8G8_UINT\0",
	"R8G8_SNORM\0",
	"R8G8_SINT\0",
	"R16_TYPELESS\0",
	"R16_FLOAT\0",
	"D16_UNORM\0",
	"R16_UNORM\0",
	"R16_UINT\0",
	"R16_SNORM\0",
	"R16_SINT\0",
	"R8_TYPELESS\0",
	"R8_UNORM\0",
	"R8_UINT\0",
	"R8_SNORM\0",
	"R8_SINT\0",
	"A8_UNORM\0",
	"R1_UNORM\0",
	"R9G9B9E5_SHAREDEXP\0",
	"R8G8_B8G8_UNORM\0",
	"G8R8_G8B8_UNORM\0",
	"BC1_TYPELESS\0",
	"BC1_UNORM\0",
	"BC1_UNORM_SRGB\0",
	"BC2_TYPELESS\0",
	"BC2_UNORM\0",
	"BC2_UNORM_SRGB\0",
	"BC3_TYPELESS\0",
	"BC3_UNORM\0",
	"BC3_UNORM_SRGB\0",
	"BC4_TYPELESS\0",
	"BC4_UNORM\0",
	"BC4_SNORM\0",
	"BC5_TYPELESS\0",
	"BC5_UNORM\0",
	"BC5_SNORM\0",
	"B5G6R5_UNORM\0",
	"B5G5R5A1_UNORM\0",
	"B8G8R8A8_UNORM\0",
	"B8G8R8X8_UNORM\0",
	"R10G10B10_XR_BIAS_A2_UNORM\0",
	"B8G8R8A8_TYPELESS\0",
	"B8G8R8A8_UNORM_SRGB\0",
	"B8G8R8X8_TYPELESS\0",
	"B8G8R8X8_UNORM_SRGB\0",
	"BC6H_TYPELESS\0",
	"BC6H_UF16\0",
	"BC6H_SF16\0",
	"BC7_TYPELESS\0",
	"BC7_UNORM\0",
	"BC7_UNORM_SRGB\0",
	"AYUV\0",
	"Y410\0",
	"Y416\0",
	"NV12\0",
	"P010\0",
	"P016\0",
	"420_OPAQUE\0",
	"YUY2\0",
	"Y210\0",
	"Y216\0",
	"NV11\0",
	"AI44\0",
	"IA44\0",
	"P8\0",
	"A8P8\0",
	"B4G4R4A4_UNORM\0",
	"P208\0",
	"V208\0",
	"V408\0"
};
const char* SYSTEM_VARIABLE_NAMES[] = {
	"--NONE--",
	"Time",
	"TimeDelta",
	"ViewportSize",
	"MousePosition",
	"View",
	"Projection",
	"ViewProjection",
	"Orthographic",
	"ViewOrthographic",
	"GeometryTransform",
	"IsPicked",
	"CameraPosition",
	"KeysWASD"
};
const char* VARIABLE_TYPE_NAMES[] = {
	"bool",
	"bool2",
	"bool3",
	"bool4",
	"int",
	"int2",
	"int3",
	"int4",
	"float",
	"float2",
	"float3",
	"float4",
	"float2x2",
	"float3x3",
	"float4x4"
};

const char* FUNCTION_NAMES[] = {
	"None",
	"MatrixIdentity",
	"MatrixLookAtLH",
	"MatrixLookToLH",
	"MatrixOrthographicLH",
	"MatrixPerspectiveFovLH",
	"MatrixPerspectiveLH",
	"MatrixReflect",
	"MatrixRotationAxis",
	"MatrixRotationNormal",
	"MatrixRotationRollPitchYaw",
	"MatrixRotationX",
	"MatrixRotationY",
	"MatrixRotationZ",
	"MatrixScaling",
	"MatrixShadow",
	"MatrixTranslation",
	"ScalarCos",
	"ScalarSin",
	"VectorNormalize"
};

const char* GEOMETRY_NAMES[] = {
	"Cube",
	"ScreenQuad",
	"Circle",
	"Triangle",
	"Sphere",
	"Plane"
};

const char* PIPELINE_ITEM_NAMES[] =
{
	"Shader Pass",
	"Geometry"
};

const char* BLEND_NAMES[] = {
	"",
	"Zero",
	"One",
	"Source Color",
	"Inverse Source Color",
	"Source Alpha",
	"Inverse Source Alpha",
	"Destination Alpha",
	"Inverse Destination Alpha",
	"Destination Color",
	"Inverse Destination Color",
	"Saturated Source Alpha",  // 11
	"", "",
	"Blend Factor",
	"Inverse Blend Factor",
	"Source 1 Color",
	"Inverse Source 1 Color",
	"Source 1 Alpha",
	"Inverse Source 1 Alpha"
};
const char* BLEND_OPERATOR_NAMES[] = {
	"",
	"Add",
	"Subtract",
	"Reverse Subtract",
	"Min",
	"Max"
};
const char* COMPARISON_FUNCTION_NAMES[] = {
	"",
	"Never",
	"Less",
	"Equal",
	"LessEqual",
	"Greater",
	"NotEqual",
	"GreaterEqual",
	"Always"
};
const char* STENCIL_OPERATION_NAMES[] = {
	"",
	"Keep",
	"Zero",
	"Replace",
	"Increase Saturated",
	"Decrease Saturated",
	"Invert",
	"Increase",
	"Decrease"
};
const char* CULL_MODE_NAMES[] = {
	"",
	"None",
	"Front",
	"Back"
};