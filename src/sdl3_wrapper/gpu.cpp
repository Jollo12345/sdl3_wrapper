#include "sdl3_wrapper/gpu.h"

#include <spdlog/spdlog.h>

#include "util.h"

bool sdl3_wrapper::gpu_supports_shader_formats(SDL_GPUShaderFormat format_flags, const std::optional<std::string>& name) {
    bool result;
    if(name.has_value()) {
        result = SDL_GPUSupportsShaderFormats(format_flags, name.value().c_str());
    } else {
        result = SDL_GPUSupportsShaderFormats(format_flags, NULL);
    }
    return result;
}

SDL_GPUDevice* sdl3_wrapper::create_gpu_device(SDL_GPUShaderFormat format_flags, bool debug_mode, const std::optional<std::string>& name) {
    SDL_GPUDevice* gpu_device;
    if(name.has_value()) {
        CHECK_ERROR(gpu_device = SDL_CreateGPUDevice(format_flags, debug_mode, name->c_str()), "SDL_CreateGPUDevice failed: {}");
    } else {
        CHECK_ERROR(gpu_device = SDL_CreateGPUDevice(format_flags, debug_mode, NULL), "SDL_CreateGPUDevice failed: {}");
    }
    return gpu_device;
}

SDL_GPUComputePipeline* sdl3_wrapper::create_gpu_compute_pipeline(SDL_GPUDevice* device, const SDL_GPUComputePipelineCreateInfo& create_info) {
    SDL_GPUComputePipeline* gpu_compute_pipeline;
    CHECK_ERROR(gpu_compute_pipeline = SDL_CreateGPUComputePipeline(device, &create_info), "SDL_CreateGPUComputePipeline failed: {}");
    return gpu_compute_pipeline;
}

SDL_GPUGraphicsPipeline* sdl3_wrapper::create_gpu_graphics_pipeline(SDL_GPUDevice* device, const SDL_GPUGraphicsPipelineCreateInfo& create_info) {
    SDL_GPUGraphicsPipeline* gpu_graphics_pipeline;
    CHECK_ERROR(gpu_graphics_pipeline = SDL_CreateGPUGraphicsPipeline(device, &create_info), "SDL_CreateGPUGraphicsPipeline failed: {}");
    return gpu_graphics_pipeline;
}

SDL_GPUSampler* sdl3_wrapper::create_gpu_sampler(SDL_GPUDevice* device, const SDL_GPUSamplerCreateInfo& create_info) {
    SDL_GPUSampler* gpu_sampler;
    CHECK_ERROR(gpu_sampler = SDL_CreateGPUSampler(device, &create_info), "SDL_CreateGPUSampler failed: {}");
    return gpu_sampler;
}

SDL_GPUShader* sdl3_wrapper::create_gpu_shader(SDL_GPUDevice* device, const SDL_GPUShaderCreateInfo& create_info) {
    SDL_GPUShader* gpu_shader;
    CHECK_ERROR(gpu_shader = SDL_CreateGPUShader(device, &create_info), "SDL_CreateGPUShader failed: {}");
    return gpu_shader;
}

SDL_GPUTexture* sdl3_wrapper::create_gpu_texture(SDL_GPUDevice* device, const SDL_GPUTextureCreateInfo& create_info) {
    SDL_GPUTexture* gpu_texture;
    CHECK_ERROR(gpu_texture = SDL_CreateGPUTexture(device, &create_info), "SDL_CreateGPUTexture failed: {}");
    return gpu_texture;
}

SDL_GPUBuffer* sdl3_wrapper::create_gpu_buffer(SDL_GPUDevice* device, const SDL_GPUBufferCreateInfo& create_info) {
    SDL_GPUBuffer* gpu_buffer;
    CHECK_ERROR(gpu_buffer = SDL_CreateGPUBuffer(device, &create_info), "SDL_CreateGPUBuffer failed: {}");
    return gpu_buffer;
}

SDL_GPUTransferBuffer* sdl3_wrapper::create_gpu_transfer_buffer(SDL_GPUDevice* device, const SDL_GPUTransferBufferCreateInfo& create_info) {
    SDL_GPUTransferBuffer* gpu_transfer_buffer;
    CHECK_ERROR(gpu_transfer_buffer = SDL_CreateGPUTransferBuffer(device, &create_info), "SDL_CreateGPUTransferBuffer failed: {}");
    return gpu_transfer_buffer;
}

void sdl3_wrapper::claim_window_for_gpu_device(SDL_GPUDevice* device, SDL_Window* window) {
    CHECK_ERROR(SDL_ClaimWindowForGPUDevice(device, window), "SDL_ClaimWindowForGPUDevice failed: {}");
}

std::tuple<SDL_GPUTexture*, Uint32, Uint32> sdl3_wrapper::wait_and_acquire_gpu_swapchain_texture(SDL_GPUCommandBuffer* command_buffer, SDL_Window* window) {
    SDL_GPUTexture* swapchain_texture;
    Uint32 swapchain_texture_width;
    Uint32 swapchain_texture_height;
    CHECK_ERROR(SDL_WaitAndAcquireGPUSwapchainTexture(command_buffer, window, &swapchain_texture, &swapchain_texture_width, &swapchain_texture_height), "SDL_WaitAndAcquireGPUSwapchainTexture failed: {}");
    return {swapchain_texture, swapchain_texture_width, swapchain_texture_height};
}

SDL_GPUCommandBuffer* sdl3_wrapper::acquire_gpu_command_buffer(SDL_GPUDevice* device) {
    SDL_GPUCommandBuffer* command_buffer;
    CHECK_ERROR(command_buffer = SDL_AcquireGPUCommandBuffer(device), "SDL_AcquireGPUCommandBuffer failed: {}");
    return command_buffer;
}

void sdl3_wrapper::submit_gpu_command_buffer(SDL_GPUCommandBuffer* command_buffer) {
    CHECK_ERROR(SDL_SubmitGPUCommandBuffer(command_buffer), "SDL_SubmitGPUCommandBuffer failed: {}");
}

sdl3_wrapper::gpu_shader_create_info::operator SDL_GPUShaderCreateInfo() const {
    return {
        .code_size = code_size,
        .code = code,
        .entrypoint = entrypoint.c_str(),
        .format = format,
        .stage = stage,
        .num_samplers = num_samplers,
        .num_storage_textures = num_storage_textures,
        .num_storage_buffers = num_storage_buffers,
        .num_uniform_buffers = num_uniform_buffers,

        .props = props,
    };
}

sdl3_wrapper::gpu_graphics_pipeline_target_info::operator SDL_GPUGraphicsPipelineTargetInfo() const {
    return {
        .color_target_descriptions = color_target_descriptions.data(),
        .num_color_targets = static_cast<Uint32>(color_target_descriptions.size()),
        .depth_stencil_format = depth_stencil_format,
        .has_depth_stencil_target = has_depth_stencil_target,
    };
}

sdl3_wrapper::gpu_compute_pipeline_create_info::operator SDL_GPUComputePipelineCreateInfo() const {
    return {
        .code_size = code_size,
        .code = code,
        .entrypoint = entrypoint.c_str(),
        .format = format,
        .num_samplers = num_samplers,
        .num_readonly_storage_textures = num_readwrite_storage_textures,
        .num_readonly_storage_buffers = num_readonly_storage_buffers,
        .num_readwrite_storage_textures = num_readwrite_storage_textures,
        .num_readwrite_storage_buffers = num_readwrite_storage_buffers,
        .num_uniform_buffers = num_uniform_buffers,
        .threadcount_x = threadcount_x,
        .threadcount_y = threadcount_y,
        .threadcount_z = threadcount_z,

        .props = props,
    };
}

sdl3_wrapper::gpu_vertex_input_state::operator SDL_GPUVertexInputState() const {
    return {
        .vertex_buffer_descriptions = vertex_buffer_descriptions.data(),
        .num_vertex_buffers = static_cast<Uint32>(vertex_buffer_descriptions.size()),
        .vertex_attributes = vertex_attributes.data(),
        .num_vertex_attributes = static_cast<Uint32>(vertex_attributes.size()),
    };
}
