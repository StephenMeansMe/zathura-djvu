/* See LICENSE file for license and copyright information */

#ifndef DJVU_H
#define DJVU_H

#include <stdbool.h>
#include <zathura/document.h>
#include <libdjvu/ddjvuapi.h>
#ifdef HAVE_CAIRO
#include <cairo.h>
#endif

typedef struct djvu_document_s
{
  ddjvu_context_t*  context;
  ddjvu_document_t* document;
  ddjvu_format_t*   format;
} djvu_document_t;

bool djvu_document_open(zathura_document_t* document);
bool djvu_document_free(zathura_document_t* document);
girara_tree_node_t* djvu_document_index_generate(zathura_document_t* document);
bool djvu_document_save_as(zathura_document_t* document, const char* path);
zathura_list_t* djvu_document_attachments_get(zathura_document_t* document);
zathura_page_t* djvu_page_get(zathura_document_t* document, unsigned int page);
zathura_list_t* djvu_page_search_text(zathura_page_t* page, const char* text);
zathura_list_t* djvu_page_links_get(zathura_page_t* page);
zathura_list_t* djvu_page_form_fields_get(zathura_page_t* page);
zathura_image_buffer_t* djvu_page_render(zathura_page_t* page);
#ifdef HAVE_CAIRO
bool djvu_page_render_cairo(zathura_page_t* page, cairo_t* cairo);
#endif
bool djvu_page_free(zathura_page_t* page);

#endif // DJVU_H
