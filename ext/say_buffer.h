#ifndef SAY_BUFFER_H_
#define SAY_BUFFER_H_

#include "say_basic_type.h"

#define SAY_STATIC  GL_STATIC_DRAW_ARB
#define SAY_STREAM  GL_STREAM_DRAW_ARB
#define SAY_DYNAMIC GL_DYNAMIC_DRAW_ARB

typedef struct {
  size_t vtype;

  GLuint vbo, instance_vbo;
  GLenum type;

  mo_hash *vaos;

  mo_array buffer, *instance_buffer;
} say_buffer;

say_buffer *say_buffer_create(size_t vtype, GLenum type, size_t size);
void say_buffer_free(say_buffer *buf);

bool say_buffer_has_instance(say_buffer *buf);

void *say_buffer_get_vertex(say_buffer *buf, size_t id);
void *say_buffer_get_instance(say_buffer *buf, size_t id);

void say_buffer_bind(say_buffer *buf);
void say_buffer_bind_vbo(say_buffer *buf);
void say_buffer_bind_instance_vbo(say_buffer *buf);

void say_buffer_unbind();
void say_buffer_unbind_vbo();

void say_buffer_update_part(say_buffer *buf, size_t index, size_t size);
void say_buffer_update(say_buffer *buf);

size_t say_buffer_get_size(say_buffer *buf);
void say_buffer_resize(say_buffer *buf, size_t size);

void say_buffer_update_instance_part(say_buffer *buf, size_t index,
                                     size_t size);
void say_buffer_update_instance(say_buffer *buf);

size_t say_buffer_get_instance_size(say_buffer *buf);
void say_buffer_resize_instance(say_buffer *buf, size_t size);

GLuint say_buffer_get_vbo(say_buffer *buf);
GLuint say_buffer_get_instance_vbo(say_buffer *buf);

#endif
