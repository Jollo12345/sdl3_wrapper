#pragma once

#include <SDL3/SDL_gpu.h>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

namespace sdl3_wrapper {

/* Functions */

bool gpu_supports_shader_formats(
    SDL_GPUShaderFormat format_flags,
    const std::optional<std::string>& name
); // SDL_GPUSupportsShaderFormats

bool gpu_supports_properties(
    SDL_PropertiesID props
); // SDL_GPUSupportsProperties

SDL_GPUDevice* create_gpu_device(
    SDL_GPUShaderFormat format_flags,
    bool debug_mode,
    const std::optional<std::string>& name
); // SDL_CreateGPUDevice

SDL_GPUDevice* create_gpu_device_with_properties(
    SDL_PropertiesID props
); // SDL_CreateGPUDeviceWithProperties

constexpr auto& destroy_gpu_device = SDL_DestroyGPUDevice; // SDL_DestroyGPUDevice

int get_num_gpu_drivers(
    void
); // SDL_GetNumGPUDrivers

const char* get_gpu_driver(
    int index
); // SDL_GetGPUDriver

const char* get_gpu_device_driver(
    SDL_GPUDevice* device
); // SDL_GetGPUDeviceDriver

SDL_GPUShaderFormat get_gpu_shader_formats(
    SDL_GPUDevice* device
); // SDL_GetGPUShaderFormats

SDL_PropertiesID get_gpu_device_properties(
    SDL_GPUDevice* device
); // SDL_GetGPUDeviceProperties

SDL_GPUComputePipeline* create_gpu_compute_pipeline(
    SDL_GPUDevice* device,
    const SDL_GPUComputePipelineCreateInfo& create_info
); // SDL_CreateGPUComputePipeline

SDL_GPUGraphicsPipeline* create_gpu_graphics_pipeline(
    SDL_GPUDevice* device,
    const SDL_GPUGraphicsPipelineCreateInfo& create_info
); // SDL_CreateGPUGraphicsPipeline

SDL_GPUSampler* create_gpu_sampler(
    SDL_GPUDevice* device,
    const SDL_GPUSamplerCreateInfo& create_info
); // SDL_CreateGPUSampler

SDL_GPUShader* create_gpu_shader(
    SDL_GPUDevice* device,
    const SDL_GPUShaderCreateInfo& create_info
); // SDL_CreateGPUShader

SDL_GPUTexture* create_gpu_texture(
    SDL_GPUDevice* device,
    const SDL_GPUTextureCreateInfo& create_info
); // SDL_CreateGPUTexture

SDL_GPUBuffer* create_gpu_buffer(
    SDL_GPUDevice* device,
    const SDL_GPUBufferCreateInfo& create_info
); // SDL_CreateGPUBuffer

SDL_GPUTransferBuffer* create_gpu_transfer_buffer(
    SDL_GPUDevice* device,
    const SDL_GPUTransferBufferCreateInfo& create_info
); // SDL_CreateGPUTransferBuffer

void set_gpu_buffer_name(
    SDL_GPUDevice* device,
    SDL_GPUBuffer* buffer,
    const char* text
); // SDL_SetGPUBufferName

void set_gpu_texture_name(
    SDL_GPUDevice* device,
    SDL_GPUTexture* texture,
    const char* text
); // SDL_SetGPUTextureName

void insert_gpu_debug_label(
    SDL_GPUCommandBuffer* command_buffer,
    const char* text
); // SDL_InsertGPUDebugLabel

void push_gpu_debug_group(
    SDL_GPUCommandBuffer* command_buffer,
    const char* name
); // SDL_PushGPUDebugGroup

void pop_gpu_debug_group(
    SDL_GPUCommandBuffer* command_buffer
); // SDL_PopGPUDebugGroup

constexpr auto& release_gpu_texture = SDL_ReleaseGPUTexture; // SDL_ReleaseGPUTexture
constexpr auto& release_gpu_sampler = SDL_ReleaseGPUSampler; // SDL_ReleaseGPUSampler
constexpr auto& release_gpu_buffer = SDL_ReleaseGPUBuffer; // SDL_ReleaseGPUBuffer
constexpr auto& release_gpu_transfer_buffer = SDL_ReleaseGPUTransferBuffer; // SDL_ReleaseGPUTransferBuffer
constexpr auto& release_gpu_compute_pipeline = SDL_ReleaseGPUComputePipeline; // SDL_ReleaseGPUComputePipeline
constexpr auto& release_gpu_shader = SDL_ReleaseGPUShader; // SDL_ReleaseGPUShader
constexpr auto& release_gpu_graphics_pipeline = SDL_ReleaseGPUGraphicsPipeline; // SDL_ReleaseGPUGraphicsPipeline

SDL_GPUCommandBuffer* acquire_gpu_command_buffer(
    SDL_GPUDevice* device
); // SDL_AcquireGPUCommandBuffer

void push_gpu_vertex_uniform_data(
    SDL_GPUCommandBuffer* command_buffer,
    Uint32 slot_index,
    const void* data,
    Uint32 length
); // SDL_PushGPUVertexUniformData

void push_gpu_fragment_uniform_data(
    SDL_GPUCommandBuffer* command_buffer,
    Uint32 slot_index,
    const void* data,
    Uint32 length
); // SDL_PushGPUFragmentUniformData

void push_gpu_compute_uniform_data(
    SDL_GPUCommandBuffer* command_buffer,
    Uint32 slot_index,
    const void* data,
    Uint32 length
); // SDL_PushGPUComputeUniformData

SDL_GPURenderPass* begin_gpu_render_pass(
    SDL_GPUCommandBuffer* command_buffer,
    const SDL_GPUColorTargetInfo* color_target_infos,
    Uint32 num_color_targets,
    const SDL_GPUDepthStencilTargetInfo* depth_stencil_target_info
); // SDL_BeginGPURenderPass

void bind_gpu_graphics_pipeline(
    SDL_GPURenderPass* render_pass,
    SDL_GPUGraphicsPipeline* graphics_pipeline
); // SDL_BindGPUGraphicsPipeline

void set_gpu_viewport(
    SDL_GPURenderPass* render_pass,
    const SDL_GPUViewport* viewport
); // SDL_SetGPUViewport

void set_gpu_scissor(
    SDL_GPURenderPass* render_pass,
    const SDL_Rect* scissor
); // SDL_SetGPUScissor

void set_gpu_blend_constants(
    SDL_GPURenderPass* render_pass,
    SDL_FColor blend_constants
); // SDL_SetGPUBlendConstants

void set_gpu_stencil_reference(
    SDL_GPURenderPass* render_pass,
    Uint8 reference
); // SDL_SetGPUStencilReference

void bind_gpu_vertex_buffers(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    const SDL_GPUBufferBinding* bindings,
    Uint32 num_bindings
); // SDL_BindGPUVertexBuffers

void bind_gpu_index_buffer(
    SDL_GPURenderPass* render_pass,
    const SDL_GPUBufferBinding* binding,
    SDL_GPUIndexElementSize index_element_size
); // SDL_BindGPUIndexBuffer

void bind_gpu_vertex_samplers(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    const SDL_GPUTextureSamplerBinding* texture_sampler_bindings,
    Uint32 num_bindings
); // SDL_BindGPUVertexSamplers

void bind_gpu_vertex_storage_textures(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    SDL_GPUTexture* const* storage_textures,
    Uint32 num_bindings
); // SDL_BindGPUVertexStorageTextures

void bind_gpu_vertex_storage_buffers(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    SDL_GPUBuffer* const* storage_buffers,
    Uint32 num_bindings
); // SDL_BindGPUVertexStorageBuffers

void bind_gpu_fragment_samplers(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    const SDL_GPUTextureSamplerBinding* texture_sampler_bindings,
    Uint32 num_bindings
); // SDL_BindGPUFragmentSamplers

void bind_gpu_fragment_storage_textures(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    SDL_GPUTexture* const* storage_textures,
    Uint32 num_bindings
); // SDL_BindGPUFragmentStorageTextures

void bind_gpu_fragment_storage_buffers(
    SDL_GPURenderPass* render_pass,
    Uint32 first_slot,
    SDL_GPUBuffer* const* storage_buffers,
    Uint32 num_bindings
); // SDL_BindGPUFragmentStorageBuffers

void draw_gpu_indexed_primitives(
    SDL_GPURenderPass* render_pass,
    Uint32 num_indices,
    Uint32 num_instances,
    Uint32 first_index,
    Sint32 vertex_offset,
    Uint32 first_instance
); // SDL_DrawGPUIndexedPrimitives

void draw_gpu_primitives(
    SDL_GPURenderPass* render_pass,
    Uint32 num_vertices,
    Uint32 num_instances,
    Uint32 first_vertex,
    Uint32 first_instance
); // SDL_DrawGPUPrimitives

void draw_gpu_primitives_indirect(
    SDL_GPURenderPass* render_pass,
    SDL_GPUBuffer* buffer,
    Uint32 offset,
    Uint32 draw_count
); // SDL_DrawGPUPrimitivesIndirect

void draw_gpu_indexed_primitives_indirect(
    SDL_GPURenderPass* render_pass,
    SDL_GPUBuffer* buffer,
    Uint32 offset,
    Uint32 draw_count
); // SDL_DrawGPUIndexedPrimitivesIndirect

void end_gpu_render_pass(
    SDL_GPURenderPass* render_pass
); // SDL_EndGPURenderPass

SDL_GPUComputePass* begin_gpu_compute_pass(
    SDL_GPUCommandBuffer* command_buffer,
    const SDL_GPUStorageTextureReadWriteBinding* storage_texture_bindings,
    Uint32 num_storage_texture_bindings,
    const SDL_GPUStorageBufferReadWriteBinding* storage_buffer_bindings,
    Uint32 num_storage_buffer_bindings
); // SDL_BeginGPUComputePass

void bind_gpu_compute_pipeline(
    SDL_GPUComputePass* compute_pass,
    SDL_GPUComputePipeline* compute_pipeline
); // SDL_BindGPUComputePipeline

void bind_gpu_compute_samplers(
    SDL_GPUComputePass* compute_pass,
    Uint32 first_slot,
    const SDL_GPUTextureSamplerBinding* texture_sampler_bindings,
    Uint32 num_bindings
); // SDL_BindGPUComputeSamplers

void bind_gpu_compute_storage_textures(
    SDL_GPUComputePass* compute_pass,
    Uint32 first_slot,
    SDL_GPUTexture* const* storage_textures,
    Uint32 num_bindings
); // SDL_BindGPUComputeStorageTextures

void bind_gpu_compute_storage_buffers(
    SDL_GPUComputePass* compute_pass,
    Uint32 first_slot,
    SDL_GPUBuffer* const* storage_buffers,
    Uint32 num_bindings
); // SDL_BindGPUComputeStorageBuffers

void dispatch_gpu_compute(
    SDL_GPUComputePass* compute_pass,
    Uint32 groupcount_x,
    Uint32 groupcount_y,
    Uint32 groupcount_z
); // SDL_DispatchGPUCompute

void dispatch_gpu_compute_indirect(
    SDL_GPUComputePass* compute_pass,
    SDL_GPUBuffer* buffer,
    Uint32 offset
); // SDL_DispatchGPUComputeIndirect

void end_gpu_compute_pass(
    SDL_GPUComputePass* compute_pass
); // SDL_EndGPUComputePass

void* map_gpu_transfer_buffer(
    SDL_GPUDevice* device,
    SDL_GPUTransferBuffer* transfer_buffer,
    bool cycle
); // SDL_MapGPUTransferBuffer

void unmap_gpu_transfer_buffer(
    SDL_GPUDevice* device,
    SDL_GPUTransferBuffer* transfer_buffer
); // SDL_UnmapGPUTransferBuffer

SDL_GPUCopyPass* begin_gpu_copy_pass(
    SDL_GPUCommandBuffer* command_buffer
); // SDL_BeginGPUCopyPass

void upload_to_gpu_texture(
    SDL_GPUCopyPass* copy_pass,
    const SDL_GPUTextureTransferInfo* source,
    const SDL_GPUTextureRegion* destination,
    bool cycle
); // SDL_UploadToGPUTexture

void upload_to_gpu_buffer(
    SDL_GPUCopyPass* copy_pass,
    const SDL_GPUTransferBufferLocation* source,
    const SDL_GPUBufferRegion* destination,
    bool cycle
); // SDL_UploadToGPUBuffer

void copy_gpu_texture_to_texture(
    SDL_GPUCopyPass* copy_pass,
    const SDL_GPUTextureLocation* source,
    const SDL_GPUTextureLocation* destination,
    Uint32 w,
    Uint32 h,
    Uint32 d,
    bool cycle
); // SDL_CopyGPUTextureToTexture

void copy_gpu_buffer_to_buffer(
    SDL_GPUCopyPass* copy_pass,
    const SDL_GPUBufferLocation* source,
    const SDL_GPUBufferLocation* destination,
    Uint32 size,
    bool cycle
); // SDL_CopyGPUBufferToBuffer

void download_from_gpu_texture(
    SDL_GPUCopyPass* copy_pass,
    const SDL_GPUTextureRegion* source,
    const SDL_GPUTextureTransferInfo* destination
); // SDL_DownloadFromGPUTexture

void download_from_gpu_buffer(
    SDL_GPUCopyPass* copy_pass,
    const SDL_GPUBufferRegion* source,
    const SDL_GPUTransferBufferLocation* destination
); // SDL_DownloadFromGPUBuffer

void end_gpu_copy_pass(
    SDL_GPUCopyPass* copy_pass
); // SDL_EndGPUCopyPass

void generate_mipmaps_for_gpu_texture(
    SDL_GPUCommandBuffer* command_buffer,
    SDL_GPUTexture* texture
); // SDL_GenerateMipmapsForGPUTexture

void blit_gpu_texture(
    SDL_GPUCommandBuffer* command_buffer,
    const SDL_GPUBlitInfo* info
); // SDL_BlitGPUTexture

bool window_supports_gpu_swapchain_composition(
    SDL_GPUDevice* device,
    SDL_Window* window,
    SDL_GPUSwapchainComposition swapchain_composition
); // SDL_WindowSupportsGPUSwapchainComposition

bool window_supports_gpu_present_mode(
    SDL_GPUDevice* device,
    SDL_Window* window,
    SDL_GPUPresentMode present_mode
); // SDL_WindowSupportsGPUPresentMode

void claim_window_for_gpu_device(
    SDL_GPUDevice* device,
    SDL_Window* window
); // SDL_ClaimWindowForGPUDevice

void release_window_from_gpu_device(
    SDL_GPUDevice* device,
    SDL_Window* window
); // SDL_ReleaseWindowFromGPUDevice

bool set_gpu_swapchain_parameters(
    SDL_GPUDevice* device,
    SDL_Window* window,
    SDL_GPUSwapchainComposition swapchain_composition,
    SDL_GPUPresentMode present_mode
); // SDL_SetGPUSwapchainParameters

bool set_gpu_allowed_frames_in_flight(
    SDL_GPUDevice* device,
    Uint32 allowed_frames_in_flight
); // SDL_SetGPUAllowedFramesInFlight

constexpr auto& get_gpu_swapchain_texture_format = SDL_GetGPUSwapchainTextureFormat; // SDL_GetGPUSwapchainTextureFormat

bool acquire_gpu_swapchain_texture(
    SDL_GPUCommandBuffer* command_buffer,
    SDL_Window* window,
    SDL_GPUTexture** swapchain_texture,
    Uint32* swapchain_texture_width,
    Uint32* swapchain_texture_height
); // SDL_AcquireGPUSwapchainTexture

bool wait_for_gpu_swapchain(
    SDL_GPUDevice* device,
    SDL_Window* window
); // SDL_WaitForGPUSwapchain

std::tuple<SDL_GPUTexture*, Uint32, Uint32> wait_and_acquire_gpu_swapchain_texture(
    SDL_GPUCommandBuffer* command_buffer,
    SDL_Window* window
); // SDL_WaitAndAcquireGPUSwapchainTexture

void submit_gpu_command_buffer(
    SDL_GPUCommandBuffer* command_buffer
); // SDL_SubmitGPUCommandBuffer

SDL_GPUFence* submit_gpu_command_buffer_and_acquire_fence(
    SDL_GPUCommandBuffer* command_buffer
); // SDL_SubmitGPUCommandBufferAndAcquireFence

bool cancel_gpu_command_buffer(
    SDL_GPUCommandBuffer* command_buffer
); // SDL_CancelGPUCommandBuffer

bool wait_for_gpu_idle(
    SDL_GPUDevice* device
); // SDL_WaitForGPUIdle

bool wait_for_gpu_fences(
    SDL_GPUDevice* device,
    bool wait_all,
    SDL_GPUFence* const* fences,
    Uint32 num_fences
); // SDL_WaitForGPUFences

bool query_gpu_fence(
    SDL_GPUDevice* device,
    SDL_GPUFence* fence
); // SDL_QueryGPUFence

void release_gpu_fence(
    SDL_GPUDevice* device,
    SDL_GPUFence* fence
); // SDL_ReleaseGPUFence

Uint32 gpu_texture_format_texel_block_size(
    SDL_GPUTextureFormat format
); // SDL_GPUTextureFormatTexelBlockSize

bool gpu_texture_supports_format(
    SDL_GPUDevice* device,
    SDL_GPUTextureFormat format,
    SDL_GPUTextureType type,
    SDL_GPUTextureUsageFlags usage
); // SDL_GPUTextureSupportsFormat

bool gpu_texture_supports_sample_count(
    SDL_GPUDevice* device,
    SDL_GPUTextureFormat format,
    SDL_GPUSampleCount sample_count
); // SDL_GPUTextureSupportsSampleCount

Uint32 calculate_gpu_texture_format_size(
    SDL_GPUTextureFormat format,
    Uint32 width,
    Uint32 height,
    Uint32 depth_or_layer_count
); // SDL_CalculateGPUTextureFormatSize

SDL_PixelFormat get_pixel_format_from_gpu_texture_format(
    SDL_GPUTextureFormat format
); // SDL_GetPixelFormatFromGPUTextureFormat

SDL_GPUTextureFormat get_gpu_texture_format_from_pixel_format(
    SDL_PixelFormat format
); // SDL_GetGPUTextureFormatFromPixelFormat

void gdk_suspend_gpu(
    SDL_GPUDevice* device
); // SDL_GDKSuspendGPU

void gdk_resume_gpu(
    SDL_GPUDevice* device
); // SDL_GDKResumeGPU

/* Datatypes */

using gpu_buffer = SDL_GPUBuffer; // SDL_GPUBuffer

enum gpu_buffer_usage_flags : SDL_GPUBufferUsageFlags {
    GPU_BUFFERUSAGE_VERTEX = SDL_GPU_BUFFERUSAGE_VERTEX, /**< Buffer is a vertex buffer. */
    GPU_BUFFERUSAGE_INDEX = SDL_GPU_BUFFERUSAGE_INDEX, /**< Buffer is an index buffer. */
    GPU_BUFFERUSAGE_INDIRECT = SDL_GPU_BUFFERUSAGE_INDIRECT, /**< Buffer is an indirect buffer. */
    GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ = SDL_GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ, /**< Buffer supports storage reads in graphics stages. */
    GPU_BUFFERUSAGE_COMPUTE_STORAGE_READ = SDL_GPU_BUFFERUSAGE_COMPUTE_STORAGE_READ, /**< Buffer supports storage reads in the compute stage. */
    GPU_BUFFERUSAGE_COMPUTE_STORAGE_WRITE = SDL_GPU_BUFFERUSAGE_COMPUTE_STORAGE_WRITE, /**< Buffer supports storage writes in the compute stage. */
}; // SDL_GPUBufferUsageFlags

enum gpu_color_component_flags : SDL_GPUColorComponentFlags {
    GPU_COLORCOMPONENT_R = SDL_GPU_COLORCOMPONENT_R, /**< the red component */
    GPU_COLORCOMPONENT_G = SDL_GPU_COLORCOMPONENT_G, /**< the green component */
    GPU_COLORCOMPONENT_B = SDL_GPU_COLORCOMPONENT_B, /**< the blue component */
    GPU_COLORCOMPONENT_A = SDL_GPU_COLORCOMPONENT_A /**< the alpha component */
}; // SDL_GPUColorComponentFlags

using gpu_command_buffer = SDL_GPUCommandBuffer; // SDL_GPUCommandBuffer
using gpu_compute_pass = SDL_GPUComputePass; // SDL_GPUComputePass
using gpu_compute_pipeline = SDL_GPUComputePipeline; // SDL_GPUComputePipeline
using gpu_copy_pass = SDL_GPUCopyPass; // SDL_GPUCopyPass
using gpu_device = SDL_GPUDevice; // SDL_GPUDevice
using gpu_fence = SDL_GPUFence; // SDL_GPUFence
using gpu_graphics_pipeline = SDL_GPUGraphicsPipeline; // SDL_GPUGraphicsPipeline
using gpu_render_pass = SDL_GPURenderPass; // SDL_GPURenderPass
using gpu_sampler = SDL_GPUSampler; // SDL_GPUSampler
using gpu_shader = SDL_GPUShader; // SDL_GPUShader

enum gpu_shader_format : SDL_GPUShaderFormat {
    GPU_SHADERFORMAT_INVALID = SDL_GPU_SHADERFORMAT_INVALID,
    GPU_SHADERFORMAT_PRIVATE = SDL_GPU_SHADERFORMAT_PRIVATE, /**< Shaders for NDA'd platforms. */
    GPU_SHADERFORMAT_SPIRV = SDL_GPU_SHADERFORMAT_SPIRV, /**< SPIR-V shaders for Vulkan. */
    GPU_SHADERFORMAT_DXBC = SDL_GPU_SHADERFORMAT_DXBC, /**< DXBC SM5_1 shaders for D3D12. */
    GPU_SHADERFORMAT_DXIL = SDL_GPU_SHADERFORMAT_DXIL, /**< DXIL SM6_0 shaders for D3D12. */
    GPU_SHADERFORMAT_MSL = SDL_GPU_SHADERFORMAT_MSL, /**< MSL shaders for Metal. */
    GPU_SHADERFORMAT_METALLIB = SDL_GPU_SHADERFORMAT_METALLIB /**< Precompiled metallib shaders for Metal. */
}; // SDL_GPUShaderFormat

using gpu_texture = SDL_GPUTexture; // SDL_GPUTexture

enum gpu_texture_usage_flags : SDL_GPUTextureUsageFlags {
    GPU_TEXTUREUSAGE_SAMPLER = SDL_GPU_TEXTUREUSAGE_SAMPLER, /**< Texture supports sampling. */
    GPU_TEXTUREUSAGE_COLOR_TARGET = SDL_GPU_TEXTUREUSAGE_COLOR_TARGET, /**< Texture is a color render target. */
    GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET = SDL_GPU_TEXTUREUSAGE_DEPTH_STENCIL_TARGET, /**< Texture is a depth stencil target. */
    GPU_TEXTUREUSAGE_GRAPHICS_STORAGE_READ = SDL_GPU_TEXTUREUSAGE_GRAPHICS_STORAGE_READ, /**< Texture supports storage reads in graphics stages. */
    GPU_TEXTUREUSAGE_COMPUTE_STORAGE_READ = SDL_GPU_TEXTUREUSAGE_COMPUTE_STORAGE_READ, /**< Texture supports storage reads in the compute stage. */
    GPU_TEXTUREUSAGE_COMPUTE_STORAGE_WRITE = SDL_GPU_TEXTUREUSAGE_COMPUTE_STORAGE_WRITE, /**< Texture supports storage writes in the compute stage. */
    GPU_TEXTUREUSAGE_COMPUTE_STORAGE_SIMULTANEOUS_READ_WRITE = SDL_GPU_TEXTUREUSAGE_COMPUTE_STORAGE_SIMULTANEOUS_READ_WRITE /**< Texture supports reads and writes in the same compute shader. This is NOT equivalent to READ | WRITE. */
}; // SDL_GPUTextureUsageFlags

using gpu_transfer_buffer = SDL_GPUTransferBuffer; // SDL_GPUTransferBuffer

/* Structs */

using gpu_blit_info = SDL_GPUBlitInfo; // SDL_GPUBlitInfo
using gpu_blit_region = SDL_GPUBlitRegion; // SDL_GPUBlitRegion
using gpu_buffer_binding = SDL_GPUBufferBinding; // SDL_GPUBufferBinding
using gpu_buffer_create_info = SDL_GPUBufferCreateInfo; // SDL_GPUBufferCreateInfo
using gpu_buffer_location = SDL_GPUBufferLocation; // SDL_GPUBufferLocation
using gpu_buffer_region = SDL_GPUBufferRegion; // SDL_GPUBufferRegion
using gpu_color_target_blend_state = SDL_GPUColorTargetBlendState; // SDL_GPUColorTargetBlendState
using gpu_color_target_description = SDL_GPUColorTargetDescription; // SDL_GPUColorTargetDescription
using gpu_color_target_info = SDL_GPUColorTargetInfo; // SDL_GPUColorTargetInfo

struct gpu_compute_pipeline_create_info {
    size_t code_size; /**< The size in bytes of the compute shader code pointed to. */
    const Uint8* code; /**< A pointer to compute shader code. */
    std::string entrypoint; /**< A pointer to a null-terminated UTF-8 string specifying the entry point function name for the shader. */
    SDL_GPUShaderFormat format; /**< The format of the compute shader code. */
    Uint32 num_samplers; /**< The number of samplers defined in the shader. */
    Uint32 num_readonly_storage_textures; /**< The number of readonly storage textures defined in the shader. */
    Uint32 num_readonly_storage_buffers; /**< The number of readonly storage buffers defined in the shader. */
    Uint32 num_readwrite_storage_textures; /**< The number of read-write storage textures defined in the shader. */
    Uint32 num_readwrite_storage_buffers; /**< The number of read-write storage buffers defined in the shader. */
    Uint32 num_uniform_buffers; /**< The number of uniform buffers defined in the shader. */
    Uint32 threadcount_x; /**< The number of threads in the X dimension. This should match the value in the shader. */
    Uint32 threadcount_y; /**< The number of threads in the Y dimension. This should match the value in the shader. */
    Uint32 threadcount_z; /**< The number of threads in the Z dimension. This should match the value in the shader. */

    SDL_PropertiesID props; /**< A properties ID for extensions. Should be 0 if no extensions are needed. */

    operator SDL_GPUComputePipelineCreateInfo() const;
}; // SDL_GPUComputePipelineCreateInfo

using gpu_depth_stencil_state = SDL_GPUDepthStencilState; // SDL_GPUDepthStencilState
using gpu_depth_stencil_target_info = SDL_GPUDepthStencilTargetInfo; // SDL_GPUDepthStencilTargetInfo
using gpu_graphics_pipeline_create_info = SDL_GPUGraphicsPipelineCreateInfo; // SDL_GPUGraphicsPipelineCreateInfo

struct gpu_graphics_pipeline_target_info {
    std::vector<SDL_GPUColorTargetDescription> color_target_descriptions; /**< A vector of color target descriptions. */
    SDL_GPUTextureFormat depth_stencil_format; /**< The pixel format of the depth-stencil target. Ignored if has_depth_stencil_target is false. */
    bool has_depth_stencil_target; /**< true specifies that the pipeline uses a depth-stencil target. */

    operator SDL_GPUGraphicsPipelineTargetInfo() const;
}; // SDL_GPUGraphicsPipelineTargetInfo

using gpu_indexed_indirect_draw_command = SDL_GPUIndexedIndirectDrawCommand; // SDL_GPUIndexedIndirectDrawCommand
using gpu_indirect_dispatch_command = SDL_GPUIndirectDispatchCommand; // SDL_GPUIndirectDispatchCommand
using gpu_indirect_draw_command = SDL_GPUIndirectDrawCommand; // SDL_GPUIndirectDrawCommand
using gpu_multisample_state = SDL_GPUMultisampleState; // SDL_GPUMultisampleState
using gpu_rasterizer_state = SDL_GPURasterizerState; // SDL_GPURasterizerState
using gpu_sampler_create_info = SDL_GPUSamplerCreateInfo; // SDL_GPUSamplerCreateInfo

struct gpu_shader_create_info {
    size_t code_size; /**< The size in bytes of the code pointed to. */
    const Uint8* code; /**< A pointer to shader code. */
    std::string entrypoint; /**< A pointer to a null-terminated UTF-8 string specifying the entry point function name for the shader. */
    SDL_GPUShaderFormat format; /**< The format of the shader code. */
    SDL_GPUShaderStage stage; /**< The stage the shader program corresponds to. */
    Uint32 num_samplers; /**< The number of samplers defined in the shader. */
    Uint32 num_storage_textures; /**< The number of storage textures defined in the shader. */
    Uint32 num_storage_buffers; /**< The number of storage buffers defined in the shader. */
    Uint32 num_uniform_buffers; /**< The number of uniform buffers defined in the shader. */

    SDL_PropertiesID props; /**< A properties ID for extensions. Should be 0 if no extensions are needed. */

    operator SDL_GPUShaderCreateInfo() const;
}; // SDL_GPUShaderCreateInfo

using gpu_stencil_op_state = SDL_GPUStencilOpState; // SDL_GPUStencilOpState
using gpu_storage_buffer_read_write_binding = SDL_GPUStorageBufferReadWriteBinding; // SDL_GPUStorageBufferReadWriteBinding
using gpu_storage_texture_read_write_binding = SDL_GPUStorageTextureReadWriteBinding; // SDL_GPUStorageTextureReadWriteBinding
using gpu_texture_create_info = SDL_GPUTextureCreateInfo; // SDL_GPUTextureCreateInfo
using gpu_texture_location = SDL_GPUTextureLocation; // SDL_GPUTextureLocation
using gpu_texture_region = SDL_GPUTextureRegion; // SDL_GPUTextureRegion
using gpu_texture_sampler_binding = SDL_GPUTextureSamplerBinding; // SDL_GPUTextureSamplerBinding
using gpu_texture_transfer_info = SDL_GPUTextureTransferInfo; // SDL_GPUTextureTransferInfo
using gpu_transfer_buffer_create_info = SDL_GPUTransferBufferCreateInfo; // SDL_GPUTransferBufferCreateInfo
using gpu_transfer_buffer_location = SDL_GPUTransferBufferLocation; // SDL_GPUTransferBufferLocation
using gpu_vertex_attribute = SDL_GPUVertexAttribute; // SDL_GPUVertexAttribute
using gpu_vertex_buffer_description = SDL_GPUVertexBufferDescription; // SDL_GPUVertexBufferDescription

struct gpu_vertex_input_state {
    std::vector<SDL_GPUVertexBufferDescription> vertex_buffer_descriptions; /**< A vector of vertex buffer descriptions. */
    std::vector<SDL_GPUVertexAttribute> vertex_attributes; /**< A vector of vertex attribute descriptions. */

    operator SDL_GPUVertexInputState() const;
}; // SDL_GPUVertexInputState

using gpu_viewport = SDL_GPUViewport; // SDL_GPUViewport

/* Enums */

constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_INVALID = SDL_GPU_BLENDFACTOR_INVALID;
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ZERO = SDL_GPU_BLENDFACTOR_ZERO; /**< 0 */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ONE = SDL_GPU_BLENDFACTOR_ONE; /**< 1 */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_SRC_COLOR = SDL_GPU_BLENDFACTOR_SRC_COLOR; /**< source color */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_COLOR; /**< 1 - source color */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_DST_COLOR = SDL_GPU_BLENDFACTOR_DST_COLOR; /**< destination color */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR = SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_COLOR; /**< 1 - destination color */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_SRC_ALPHA = SDL_GPU_BLENDFACTOR_SRC_ALPHA; /**< source alpha */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA = SDL_GPU_BLENDFACTOR_ONE_MINUS_SRC_ALPHA; /**< 1 - source alpha */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_DST_ALPHA = SDL_GPU_BLENDFACTOR_DST_ALPHA; /**< destination alpha */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA = SDL_GPU_BLENDFACTOR_ONE_MINUS_DST_ALPHA; /**< 1 - destination alpha */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_CONSTANT_COLOR = SDL_GPU_BLENDFACTOR_CONSTANT_COLOR; /**< blend constant */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR = SDL_GPU_BLENDFACTOR_ONE_MINUS_CONSTANT_COLOR; /**< 1 - blend constant */
constexpr SDL_GPUBlendFactor GPU_BLENDFACTOR_SRC_ALPHA_SATURATE = SDL_GPU_BLENDFACTOR_SRC_ALPHA_SATURATE; /**< min(source alpha, 1 - destination alpha) */
using gpu_blend_factor = SDL_GPUBlendFactor; // SDL_GPUBlendFactor

constexpr SDL_GPUBlendOp GPU_BLENDOP_INVALID = SDL_GPU_BLENDOP_INVALID;
constexpr SDL_GPUBlendOp GPU_BLENDOP_ADD = SDL_GPU_BLENDOP_ADD; /**< (source * source_factor) + (destination * destination_factor) */
constexpr SDL_GPUBlendOp GPU_BLENDOP_SUBTRACT = SDL_GPU_BLENDOP_SUBTRACT; /**< (source * source_factor) - (destination * destination_factor) */
constexpr SDL_GPUBlendOp GPU_BLENDOP_REVERSE_SUBTRACT = SDL_GPU_BLENDOP_REVERSE_SUBTRACT; /**< (destination * destination_factor) - (source * source_factor) */
constexpr SDL_GPUBlendOp GPU_BLENDOP_MIN = SDL_GPU_BLENDOP_MIN; /**< min(source, destination) */
constexpr SDL_GPUBlendOp GPU_BLENDOP_MAX = SDL_GPU_BLENDOP_MAX; /**< max(source, destination) */
using gpu_blend_op = SDL_GPUBlendOp; // SDL_GPUBlendOp

constexpr SDL_GPUCompareOp GPU_COMPAREOP_INVALID = SDL_GPU_COMPAREOP_INVALID;
constexpr SDL_GPUCompareOp GPU_COMPAREOP_NEVER = SDL_GPU_COMPAREOP_NEVER; /**< The comparison always evaluates false. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_LESS = SDL_GPU_COMPAREOP_LESS; /**< The comparison evaluates reference < test. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_EQUAL = SDL_GPU_COMPAREOP_EQUAL; /**< The comparison evaluates reference == test. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_LESS_OR_EQUAL = SDL_GPU_COMPAREOP_LESS_OR_EQUAL; /**< The comparison evaluates reference <= test. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_GREATER = SDL_GPU_COMPAREOP_GREATER; /**< The comparison evaluates reference > test. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_NOT_EQUAL = SDL_GPU_COMPAREOP_NOT_EQUAL; /**< The comparison evaluates reference != test. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_GREATER_OR_EQUAL = SDL_GPU_COMPAREOP_GREATER_OR_EQUAL; /**< The comparison evaluates reference >= test. */
constexpr SDL_GPUCompareOp GPU_COMPAREOP_ALWAYS = SDL_GPU_COMPAREOP_ALWAYS; /**< The comparison always evaluates true. */
using gpu_compare_op = SDL_GPUCompareOp; // SDL_GPUCompareOp

constexpr SDL_GPUCubeMapFace GPU_CUBEMAPFACE_POSITIVEX = SDL_GPU_CUBEMAPFACE_POSITIVEX;
constexpr SDL_GPUCubeMapFace GPU_CUBEMAPFACE_NEGATIVEX = SDL_GPU_CUBEMAPFACE_NEGATIVEX;
constexpr SDL_GPUCubeMapFace GPU_CUBEMAPFACE_POSITIVEY = SDL_GPU_CUBEMAPFACE_POSITIVEY;
constexpr SDL_GPUCubeMapFace GPU_CUBEMAPFACE_NEGATIVEY = SDL_GPU_CUBEMAPFACE_NEGATIVEY;
constexpr SDL_GPUCubeMapFace GPU_CUBEMAPFACE_POSITIVEZ = SDL_GPU_CUBEMAPFACE_POSITIVEZ;
constexpr SDL_GPUCubeMapFace GPU_CUBEMAPFACE_NEGATIVEZ = SDL_GPU_CUBEMAPFACE_NEGATIVEZ;
using gpu_cube_map_face = SDL_GPUCubeMapFace; // SDL_GPUCubeMapFace

constexpr SDL_GPUCullMode GPU_CULLMODE_NONE = SDL_GPU_CULLMODE_NONE; /**< No triangles are culled. */
constexpr SDL_GPUCullMode GPU_CULLMODE_FRONT = SDL_GPU_CULLMODE_FRONT; /**< Front-facing triangles are culled. */
constexpr SDL_GPUCullMode GPU_CULLMODE_BACK = SDL_GPU_CULLMODE_BACK; /**< Back-facing triangles are culled. */
using gpu_cull_mode = SDL_GPUCullMode; // SDL_GPUCullMode

constexpr SDL_GPUFillMode GPU_FILLMODE_FILL = SDL_GPU_FILLMODE_FILL; /**< Polygons will be rendered via rasterization. */
constexpr SDL_GPUFillMode GPU_FILLMODE_LINE = SDL_GPU_FILLMODE_LINE; /**< Polygon edges will be drawn as line segments. */
using gpu_fill_mode = SDL_GPUFillMode; // SDL_GPUFillMode

constexpr SDL_GPUFilter GPU_FILTER_NEAREST = SDL_GPU_FILTER_NEAREST; /**< Point filtering. */
constexpr SDL_GPUFilter GPU_FILTER_LINEAR = SDL_GPU_FILTER_LINEAR; /**< Linear filtering. */
using gpu_filter = SDL_GPUFilter; // SDL_GPUFilter

constexpr SDL_GPUFrontFace GPU_FRONTFACE_COUNTER_CLOCKWISE = SDL_GPU_FRONTFACE_COUNTER_CLOCKWISE; /**< A triangle with counter-clockwise vertex winding will be considered front-facing. */
constexpr SDL_GPUFrontFace GPU_FRONTFACE_CLOCKWISE = SDL_GPU_FRONTFACE_CLOCKWISE; /**< A triangle with clockwise vertex winding will be considered front-facing. */
using gpu_front_face = SDL_GPUFrontFace; // SDL_GPUFrontFace

constexpr SDL_GPUIndexElementSize GPU_INDEXELEMENTSIZE_16BIT = SDL_GPU_INDEXELEMENTSIZE_16BIT; /**< The index elements are 16-bit. */
constexpr SDL_GPUIndexElementSize GPU_INDEXELEMENTSIZE_32BIT = SDL_GPU_INDEXELEMENTSIZE_32BIT; /**< The index elements are 32-bit. */
using gpu_index_element_size = SDL_GPUIndexElementSize; // SDL_GPUIndexElementSize

constexpr SDL_GPULoadOp GPU_LOADOP_LOAD = SDL_GPU_LOADOP_LOAD; /**< The previous contents of the texture will be preserved. */
constexpr SDL_GPULoadOp GPU_LOADOP_CLEAR = SDL_GPU_LOADOP_CLEAR; /**< The contents of the texture will be cleared to a color. */
constexpr SDL_GPULoadOp GPU_LOADOP_DONT_CARE = SDL_GPU_LOADOP_DONT_CARE; /**< The previous contents of the texture need not be preserved. The contents will be undefined. */
using gpu_load_op = SDL_GPULoadOp; // SDL_GPULoadOp

constexpr SDL_GPUPresentMode GPU_PRESENTMODE_VSYNC = SDL_GPU_PRESENTMODE_VSYNC;
constexpr SDL_GPUPresentMode GPU_PRESENTMODE_IMMEDIATE = SDL_GPU_PRESENTMODE_IMMEDIATE;
constexpr SDL_GPUPresentMode GPU_PRESENTMODE_MAILBOX = SDL_GPU_PRESENTMODE_MAILBOX;
using gpu_present_mode = SDL_GPUPresentMode; // SDL_GPUPresentMode

constexpr SDL_GPUPrimitiveType GPU_PRIMITIVETYPE_TRIANGLELIST = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST; /**< A series of separate triangles. */
constexpr SDL_GPUPrimitiveType GPU_PRIMITIVETYPE_TRIANGLESTRIP = SDL_GPU_PRIMITIVETYPE_TRIANGLESTRIP; /**< A series of connected triangles. */
constexpr SDL_GPUPrimitiveType GPU_PRIMITIVETYPE_LINELIST = SDL_GPU_PRIMITIVETYPE_LINELIST; /**< A series of separate lines. */
constexpr SDL_GPUPrimitiveType GPU_PRIMITIVETYPE_LINESTRIP = SDL_GPU_PRIMITIVETYPE_LINESTRIP; /**< A series of connected lines. */
constexpr SDL_GPUPrimitiveType GPU_PRIMITIVETYPE_POINTLIST = SDL_GPU_PRIMITIVETYPE_POINTLIST; /**< A series of separate points. */
using gpu_primitive_type = SDL_GPUPrimitiveType; // SDL_GPUPrimitiveType

constexpr SDL_GPUSampleCount GPU_SAMPLECOUNT_1 = SDL_GPU_SAMPLECOUNT_1; /**< No multisampling. */
constexpr SDL_GPUSampleCount GPU_SAMPLECOUNT_2 = SDL_GPU_SAMPLECOUNT_2; /**< MSAA 2x */
constexpr SDL_GPUSampleCount GPU_SAMPLECOUNT_4 = SDL_GPU_SAMPLECOUNT_4; /**< MSAA 4x */
constexpr SDL_GPUSampleCount GPU_SAMPLECOUNT_8 = SDL_GPU_SAMPLECOUNT_8; /**< MSAA 8x */
using gpu_sample_count = SDL_GPUSampleCount; // SDL_GPUSampleCount

constexpr SDL_GPUSamplerAddressMode GPU_SAMPLERADDRESSMODE_REPEAT = SDL_GPU_SAMPLERADDRESSMODE_REPEAT; /**< Specifies that the coordinates will wrap around. */
constexpr SDL_GPUSamplerAddressMode GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT = SDL_GPU_SAMPLERADDRESSMODE_MIRRORED_REPEAT; /**< Specifies that the coordinates will wrap around mirrored. */
constexpr SDL_GPUSamplerAddressMode GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE; /**< Specifies that the coordinates will clamp to the 0-1 range. */
using gpu_sampler_address_mode = SDL_GPUSamplerAddressMode; // SDL_GPUSamplerAddressMode

constexpr SDL_GPUSamplerMipmapMode GPU_SAMPLERMIPMAPMODE_NEAREST = SDL_GPU_SAMPLERMIPMAPMODE_NEAREST; /**< Point filtering. */
constexpr SDL_GPUSamplerMipmapMode GPU_SAMPLERMIPMAPMODE_LINEAR = SDL_GPU_SAMPLERMIPMAPMODE_LINEAR; /**< Linear filtering. */
using gpu_sampler_mipmap_mode = SDL_GPUSamplerMipmapMode; // SDL_GPUSamplerMipmapMode

constexpr SDL_GPUShaderStage GPU_SHADERSTAGE_VERTEX = SDL_GPU_SHADERSTAGE_VERTEX;
constexpr SDL_GPUShaderStage GPU_SHADERSTAGE_FRAGMENT = SDL_GPU_SHADERSTAGE_FRAGMENT;
using gpu_shader_stage = SDL_GPUShaderStage; // SDL_GPUShaderStage

constexpr SDL_GPUStencilOp GPU_STENCILOP_INVALID = SDL_GPU_STENCILOP_INVALID;
constexpr SDL_GPUStencilOp GPU_STENCILOP_KEEP = SDL_GPU_STENCILOP_KEEP; /**< Keeps the current value. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_ZERO = SDL_GPU_STENCILOP_ZERO; /**< Sets the value to 0. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_REPLACE = SDL_GPU_STENCILOP_REPLACE; /**< Sets the value to reference. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_INCREMENT_AND_CLAMP = SDL_GPU_STENCILOP_INCREMENT_AND_CLAMP; /**< Increments the current value and clamps to the maximum value. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_DECREMENT_AND_CLAMP = SDL_GPU_STENCILOP_DECREMENT_AND_CLAMP; /**< Decrements the current value and clamps to 0. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_INVERT = SDL_GPU_STENCILOP_INVERT; /**< Bitwise-inverts the current value. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_INCREMENT_AND_WRAP = SDL_GPU_STENCILOP_INCREMENT_AND_WRAP; /**< Increments the current value and wraps back to 0. */
constexpr SDL_GPUStencilOp GPU_STENCILOP_DECREMENT_AND_WRAP = SDL_GPU_STENCILOP_DECREMENT_AND_WRAP; /**< Decrements the current value and wraps to the maximum value. */
using gpu_stencil_op = SDL_GPUStencilOp; // SDL_GPUStencilOp

constexpr SDL_GPUStoreOp GPU_STOREOP_STORE = SDL_GPU_STOREOP_STORE; /**< The contents generated during the render pass will be written to memory. */
constexpr SDL_GPUStoreOp GPU_STOREOP_DONT_CARE = SDL_GPU_STOREOP_DONT_CARE; /**< The contents generated during the render pass are not needed and may be discarded. The contents will be undefined. */
constexpr SDL_GPUStoreOp GPU_STOREOP_RESOLVE = SDL_GPU_STOREOP_RESOLVE; /**< The multisample contents generated during the render pass will be resolved to a non-multisample texture. The contents in the multisample texture may then be discarded and will be undefined. */
constexpr SDL_GPUStoreOp GPU_STOREOP_RESOLVE_AND_STORE = SDL_GPU_STOREOP_RESOLVE_AND_STORE; /**< The multisample contents generated during the render pass will be resolved to a non-multisample texture. The contents in the multisample texture will be written to memory. */
using gpu_store_op = SDL_GPUStoreOp; // SDL_GPUStoreOp

constexpr SDL_GPUSwapchainComposition GPU_SWAPCHAINCOMPOSITION_SDR = SDL_GPU_SWAPCHAINCOMPOSITION_SDR;
constexpr SDL_GPUSwapchainComposition GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR = SDL_GPU_SWAPCHAINCOMPOSITION_SDR_LINEAR;
constexpr SDL_GPUSwapchainComposition GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR = SDL_GPU_SWAPCHAINCOMPOSITION_HDR_EXTENDED_LINEAR;
constexpr SDL_GPUSwapchainComposition GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084 = SDL_GPU_SWAPCHAINCOMPOSITION_HDR10_ST2084;
using gpu_swapchain_composition = SDL_GPUSwapchainComposition; // SDL_GPUSwapchainComposition

constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_INVALID = SDL_GPU_TEXTUREFORMAT_INVALID;
/* Unsigned Normalized Float Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_A8_UNORM = SDL_GPU_TEXTUREFORMAT_A8_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8_UNORM = SDL_GPU_TEXTUREFORMAT_R8_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8_UNORM = SDL_GPU_TEXTUREFORMAT_R8G8_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8B8A8_UNORM = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16_UNORM = SDL_GPU_TEXTUREFORMAT_R16_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16_UNORM = SDL_GPU_TEXTUREFORMAT_R16G16_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16B16A16_UNORM = SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R10G10B10A2_UNORM = SDL_GPU_TEXTUREFORMAT_R10G10B10A2_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_B5G6R5_UNORM = SDL_GPU_TEXTUREFORMAT_B5G6R5_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_B5G5R5A1_UNORM = SDL_GPU_TEXTUREFORMAT_B5G5R5A1_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_B4G4R4A4_UNORM = SDL_GPU_TEXTUREFORMAT_B4G4R4A4_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_B8G8R8A8_UNORM = SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM;
/* Compressed Unsigned Normalized Float Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC1_RGBA_UNORM = SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC2_RGBA_UNORM = SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC3_RGBA_UNORM = SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC4_R_UNORM = SDL_GPU_TEXTUREFORMAT_BC4_R_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC5_RG_UNORM = SDL_GPU_TEXTUREFORMAT_BC5_RG_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC7_RGBA_UNORM = SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM;
/* Compressed Signed Float Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT = SDL_GPU_TEXTUREFORMAT_BC6H_RGB_FLOAT;
/* Compressed Unsigned Float Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT = SDL_GPU_TEXTUREFORMAT_BC6H_RGB_UFLOAT;
/* Signed Normalized Float Color Formats  */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8_SNORM = SDL_GPU_TEXTUREFORMAT_R8_SNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8_SNORM = SDL_GPU_TEXTUREFORMAT_R8G8_SNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8B8A8_SNORM = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_SNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16_SNORM = SDL_GPU_TEXTUREFORMAT_R16_SNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16_SNORM = SDL_GPU_TEXTUREFORMAT_R16G16_SNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16B16A16_SNORM = SDL_GPU_TEXTUREFORMAT_R16G16B16A16_SNORM;
/* Signed Float Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16_FLOAT = SDL_GPU_TEXTUREFORMAT_R16_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16_FLOAT = SDL_GPU_TEXTUREFORMAT_R16G16_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT = SDL_GPU_TEXTUREFORMAT_R16G16B16A16_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32_FLOAT = SDL_GPU_TEXTUREFORMAT_R32_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32G32_FLOAT = SDL_GPU_TEXTUREFORMAT_R32G32_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT = SDL_GPU_TEXTUREFORMAT_R32G32B32A32_FLOAT;
/* Unsigned Float Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R11G11B10_UFLOAT = SDL_GPU_TEXTUREFORMAT_R11G11B10_UFLOAT;
/* Unsigned Integer Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8_UINT = SDL_GPU_TEXTUREFORMAT_R8_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8_UINT = SDL_GPU_TEXTUREFORMAT_R8G8_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8B8A8_UINT = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16_UINT = SDL_GPU_TEXTUREFORMAT_R16_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16_UINT = SDL_GPU_TEXTUREFORMAT_R16G16_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16B16A16_UINT = SDL_GPU_TEXTUREFORMAT_R16G16B16A16_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32_UINT = SDL_GPU_TEXTUREFORMAT_R32_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32G32_UINT = SDL_GPU_TEXTUREFORMAT_R32G32_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32G32B32A32_UINT = SDL_GPU_TEXTUREFORMAT_R32G32B32A32_UINT;
/* Signed Integer Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8_INT = SDL_GPU_TEXTUREFORMAT_R8_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8_INT = SDL_GPU_TEXTUREFORMAT_R8G8_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8B8A8_INT = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16_INT = SDL_GPU_TEXTUREFORMAT_R16_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16_INT = SDL_GPU_TEXTUREFORMAT_R16G16_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R16G16B16A16_INT = SDL_GPU_TEXTUREFORMAT_R16G16B16A16_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32_INT = SDL_GPU_TEXTUREFORMAT_R32_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32G32_INT = SDL_GPU_TEXTUREFORMAT_R32G32_INT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R32G32B32A32_INT = SDL_GPU_TEXTUREFORMAT_R32G32B32A32_INT;
/* SRGB Unsigned Normalized Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM_SRGB;
/* Compressed SRGB Unsigned Normalized Color Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_BC1_RGBA_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_BC2_RGBA_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_BC3_RGBA_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_BC7_RGBA_UNORM_SRGB;
/* Depth Formats */
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_D16_UNORM = SDL_GPU_TEXTUREFORMAT_D16_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_D24_UNORM = SDL_GPU_TEXTUREFORMAT_D24_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_D32_FLOAT = SDL_GPU_TEXTUREFORMAT_D32_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT = SDL_GPU_TEXTUREFORMAT_D24_UNORM_S8_UINT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT = SDL_GPU_TEXTUREFORMAT_D32_FLOAT_S8_UINT;
/* Compressed ASTC Normalized Float Color Formats*/
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_4x4_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_5x4_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_5x5_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_6x5_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_6x6_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x5_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x6_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x8_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x5_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x6_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x8_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x10_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_12x10_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_12x12_UNORM = SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM;
/* Compressed SRGB ASTC Normalized Float Color Formats*/
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_4x4_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_5x4_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_5x5_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_6x5_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_6x6_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_8x5_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_8x6_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_8x8_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_10x5_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_10x6_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_10x8_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_10x10_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_12x10_UNORM_SRGB;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB = SDL_GPU_TEXTUREFORMAT_ASTC_12x12_UNORM_SRGB;
/* Compressed ASTC Signed Float Color Formats*/
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_4x4_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_5x4_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_5x5_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_6x5_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_6x6_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_8x5_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_8x6_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_8x8_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_10x5_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_10x6_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_10x8_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_10x10_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_12x10_FLOAT;
constexpr SDL_GPUTextureFormat GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT = SDL_GPU_TEXTUREFORMAT_ASTC_12x12_FLOAT;
using gpu_texture_format = SDL_GPUTextureFormat; // SDL_GPUTextureFormat

constexpr SDL_GPUTextureType GPU_TEXTURETYPE_2D = SDL_GPU_TEXTURETYPE_2D; /**< The texture is a 2-dimensional image. */
constexpr SDL_GPUTextureType GPU_TEXTURETYPE_2D_ARRAY = SDL_GPU_TEXTURETYPE_2D_ARRAY; /**< The texture is a 2-dimensional array image. */
constexpr SDL_GPUTextureType GPU_TEXTURETYPE_3D = SDL_GPU_TEXTURETYPE_3D; /**< The texture is a 3-dimensional image. */
constexpr SDL_GPUTextureType GPU_TEXTURETYPE_CUBE = SDL_GPU_TEXTURETYPE_CUBE; /**< The texture is a cube image. */
constexpr SDL_GPUTextureType GPU_TEXTURETYPE_CUBE_ARRAY = SDL_GPU_TEXTURETYPE_CUBE_ARRAY; /**< The texture is a cube array image. */
using gpu_texture_type = SDL_GPUTextureType; // SDL_GPUTextureType

constexpr SDL_GPUTransferBufferUsage GPU_TRANSFERBUFFERUSAGE_UPLOAD = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
constexpr SDL_GPUTransferBufferUsage GPU_TRANSFERBUFFERUSAGE_DOWNLOAD = SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD;
using gpu_transfer_buffer_usage = SDL_GPUTransferBufferUsage; // SDL_GPUTransferBufferUsage

constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_INVALID = SDL_GPU_VERTEXELEMENTFORMAT_INVALID;
/* 32-bit Signed Integers */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_INT = SDL_GPU_VERTEXELEMENTFORMAT_INT;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_INT2 = SDL_GPU_VERTEXELEMENTFORMAT_INT2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_INT3 = SDL_GPU_VERTEXELEMENTFORMAT_INT3;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_INT4 = SDL_GPU_VERTEXELEMENTFORMAT_INT4;
/* 32-bit Unsigned Integers */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UINT = SDL_GPU_VERTEXELEMENTFORMAT_UINT;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UINT2 = SDL_GPU_VERTEXELEMENTFORMAT_UINT2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UINT3 = SDL_GPU_VERTEXELEMENTFORMAT_UINT3;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UINT4 = SDL_GPU_VERTEXELEMENTFORMAT_UINT4;
/* 32-bit Floats */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_FLOAT = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_FLOAT2 = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_FLOAT3 = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_FLOAT4 = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT4;
/* 8-bit Signed Integers */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_BYTE2 = SDL_GPU_VERTEXELEMENTFORMAT_BYTE2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_BYTE4 = SDL_GPU_VERTEXELEMENTFORMAT_BYTE4;
/* 8-bit Unsigned Integers */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UBYTE2 = SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UBYTE4 = SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4;
/* 8-bit Signed Normalized */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_BYTE2_NORM = SDL_GPU_VERTEXELEMENTFORMAT_BYTE2_NORM;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_BYTE4_NORM = SDL_GPU_VERTEXELEMENTFORMAT_BYTE4_NORM;
/* 8-bit Unsigned Normalized */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM = SDL_GPU_VERTEXELEMENTFORMAT_UBYTE2_NORM;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM = SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM;
/* 16-bit Signed Integers */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_SHORT2 = SDL_GPU_VERTEXELEMENTFORMAT_SHORT2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_SHORT4 = SDL_GPU_VERTEXELEMENTFORMAT_SHORT4;
/* 16-bit Unsigned Integers */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_USHORT2 = SDL_GPU_VERTEXELEMENTFORMAT_USHORT2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_USHORT4 = SDL_GPU_VERTEXELEMENTFORMAT_USHORT4;
/* 16-bit Signed Normalized */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_SHORT2_NORM = SDL_GPU_VERTEXELEMENTFORMAT_SHORT2_NORM;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_SHORT4_NORM = SDL_GPU_VERTEXELEMENTFORMAT_SHORT4_NORM;
/* 16-bit Unsigned Normalized */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_USHORT2_NORM = SDL_GPU_VERTEXELEMENTFORMAT_USHORT2_NORM;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_USHORT4_NORM = SDL_GPU_VERTEXELEMENTFORMAT_USHORT4_NORM;
/* 16-bit Floats */
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_HALF2 = SDL_GPU_VERTEXELEMENTFORMAT_HALF2;
constexpr SDL_GPUVertexElementFormat GPU_VERTEXELEMENTFORMAT_HALF4 = SDL_GPU_VERTEXELEMENTFORMAT_HALF4;
using gpu_vertex_element_format = SDL_GPUVertexElementFormat; // SDL_GPUVertexElementFormat

constexpr SDL_GPUVertexInputRate GPU_VERTEXINPUTRATE_VERTEX = SDL_GPU_VERTEXINPUTRATE_VERTEX; /**< Attribute addressing is a function of the vertex index. */
constexpr SDL_GPUVertexInputRate GPU_VERTEXINPUTRATE_INSTANCE = SDL_GPU_VERTEXINPUTRATE_INSTANCE; /**< Attribute addressing is a function of the instance index. */
using gpu_vertex_input_rate = SDL_GPUVertexInputRate; // SDL_GPUVertexInputRate

/* Macros */

} // namespace sdl3_wrapper
