/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file blender/editors/space_layers/layers_intern.h
 *  \ingroup splayers
 */

#ifndef __LAYERS_INTERN_H__
#define __LAYERS_INTERN_H__

struct ARegion;
struct SpaceLayers;
struct wmKeyConfig;

#define LAYERTILE_HEADER_HEIGHT UI_UNIT_Y

/* layers_draw.c */
void layers_tiles_draw(const struct bContext *C, struct ARegion *ar);
void layer_group_draw(const struct bContext *C, struct LayerTreeItem *litem, struct uiLayout *layout);
void object_layer_draw(const struct bContext *C, struct LayerTreeItem *litem, struct uiLayout *layout);
void object_layer_draw_settings(const struct bContext *C, struct LayerTreeItem *litem, struct uiLayout *layout);

/* layers_util.c */
void       layers_data_refresh(const struct Scene *scene, struct SpaceLayers *slayer);
void       layers_tilehash_delete(SpaceLayers *slayer);
LayerTile *layers_tile_add(const struct SpaceLayers *slayer, struct LayerTreeItem *litem);
void       layers_tile_remove(const struct SpaceLayers *slayer, LayerTile *tile, const bool remove_children);
LayerTile *layers_tile_find_at_coordinate(struct SpaceLayers *slayer, const int co[2]);
bool layers_any_selected(struct SpaceLayers *slayer);

/* layers_ops.c */
void layers_operatortypes(void);
void layers_keymap(struct wmKeyConfig *keyconf);

/* layers_types.c */
struct LayerTreeItem *layers_object_add(struct LayerTree *ltree, const char *name);
struct LayerTreeItem *layers_group_add(struct LayerTree *ltree, const char *name);

#endif  /* __LAYERS_INTERN_H__ */

