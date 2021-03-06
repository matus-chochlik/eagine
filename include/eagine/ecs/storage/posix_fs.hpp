/**
 *  @file eagine/ecs/storage/posix_fs.hpp
 *  @brief Storages based on files stored in a POSIX filesystem
 *
 *  Copyright 2014-2015 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#pragma once

#ifndef EAGINE_ECS_STORAGE_POSIX_FS_1408161720_HPP
#define EAGINE_ECS_STORAGE_POSIX_FS_1408161720_HPP

#include <eagine/ecs/storage.hpp>
#include <eagine/base/string.hpp>
#include <eagine/base/memory.hpp>
#include <eagine/meta/type_traits.hpp>

#include <sys/types.h>
#include <dirent.h>

namespace eagine {
namespace ecs {

// posix_fs_component_io
template <typename Component>
struct posix_fs_component_io
{
	virtual ~posix_fs_component_io(void) { }

	virtual bool read(
		const base::cstrref& path,
		Component& dst
	) = 0;

	virtual bool write(
		const base::cstrref& path,
		const Component& src
	) = 0;
};

// posix_fs_base_storage - fwd
template <typename Entity>
class posix_fs_base_storage;

// posix_fs_storage_iterator
template <typename Entity>
class posix_fs_storage_iterator
 : public storage_iterator<Entity>
{
protected:
	posix_fs_base_storage<Entity>& _storage;
private:
	int _de_pos, _de_count;
	::dirent **_de_list;

	void _init(bool force_rewind = false);
	void _skip(void);

	Entity _ent;
public:
	posix_fs_storage_iterator(posix_fs_base_storage<Entity>& storage);

	posix_fs_storage_iterator(posix_fs_storage_iterator&&);
	posix_fs_storage_iterator(const posix_fs_storage_iterator&);
	~posix_fs_storage_iterator(void);

	void reset(void) override;
	bool done(void) override;
	void next(void) override;
	const Entity& current(void) override;
};

// posix_fs_base_storage
template <typename Entity>
class posix_fs_base_storage
 : public virtual base_storage<Entity>
{
protected:
	base::string _prefix;
	base::string _suffix;

	typedef posix_fs_storage_iterator<Entity> _ns_iter_t;
	_ns_iter_t _iter;
	bool _iter_taken;

	friend class posix_fs_storage_iterator<Entity>;

	posix_fs_base_storage(const posix_fs_base_storage&) = delete;

	typedef base::string _path_str_t;

	_path_str_t _get_path(const Entity&) const;
	_path_str_t _get_hdn_path(const Entity&) const;
public:
	typedef storage_iterator<Entity> iter_t;

	posix_fs_base_storage(
		base::string&& prefix,
		base::string&& suffix
	): _prefix(std::move(prefix))
	 , _suffix(std::move(suffix))
	 , _iter(*this)
	 , _iter_taken(false)
	{ }

	iter_t* new_iterator(void) override;
	iter_t* clone_iterator(iter_t*) override;
	void delete_iterator(iter_t* iter) override;

	bool _has_file(const base::cstrref& path);
	bool has(const Entity& ent) override;
	bool find(const Entity& ent, iter_t& pos) override;

	bool hidden(const Entity& ent, iter_t* pos) override;
	bool hide(const Entity& ent, iter_t* pos) override;
	bool show(const Entity& ent, iter_t* pos) override;
	void swap(const Entity& to, const Entity& from) override;
};

// posix_fs_component_storage
template <typename Entity, typename Component>
class posix_fs_component_storage
 : public posix_fs_base_storage<Entity>
 , public component_storage<Entity, Component>
{
private:
	typedef posix_fs_storage_iterator<Entity> _ns_iter_t;

	base::shared_ptr<posix_fs_component_io<Component>> _cmp_io;
public:
	typedef storage_iterator<Entity> iter_t;

	posix_fs_component_storage(
		base::string&& prefix,
		base::string&& suffix,
		const base::shared_ptr<posix_fs_component_io<Component>>& cmp_io
	): posix_fs_base_storage<Entity>(std::move(prefix), std::move(suffix))
	 , _cmp_io(cmp_io)
	{
		assert(_cmp_io);
	}

	storage_capabilities capabilities(void) const override;

	void reserve(std::size_t count) override;

	void remove_if(
		const base::callable_ref<
			bool(const Entity&, const Component&)
		>& predicate
	) override;

	void store(
		Component&& src,
		const Entity& ent,
		iter_t* pos,
		iter_t* res
	) override;

	bool copy(
		const Entity& to,
		const Entity& from,
		iter_t* pos,
		iter_t* res
	) override;

	bool remove(const Entity& from, iter_t* pos) override;

	const Component* read(const Entity& ent, iter_t* pos) override;

	Component* write(const Entity& ent, iter_t* pos) override;

	bool _fetch(Component&, const Entity&, iter_t*, meta::true_type);
	bool _fetch(Component&, const Entity&, iter_t*, meta::false_type);
	bool fetch(Component& dst, const Entity& ent, iter_t* pos) override;

	template <typename Func, typename IsConst>
	bool _for_single(const Func&, const Entity&, iter_t*, IsConst);

	bool for_single(
		const base::callable_ref<
			void(const Entity&, const Component&)
		>& func,
		const Entity& ent,
		iter_t* pos
	) override;

	bool for_single(
		const base::callable_ref<
			void(const Entity&, Component&)
		>& func,
		const Entity& ent,
		iter_t* pos
	) override;

	template <typename Func, typename IsConst>
	void _for_each(const Func&, IsConst);

	void for_each(
		const base::callable_ref<
			void(const Entity&, const Component&)
		>& func
	) override;

	void for_each(
		const base::callable_ref<
			void(const Entity&, Component&)
		>& func
	) override;

	template <typename Func, typename IsConst>
	void _parallel_for_each(
		const Func&,
		base::parallelizer&,
		base::execution_params&,
		IsConst
	);

	void parallel_for_each(
		const base::callable_ref<
			void(const Entity&, const Component&)
		>& kernel,
		base::parallelizer&,
		base::execution_params&
	) override;

	void parallel_for_each(
		const base::callable_ref<
			void(const Entity&, Component&)
		>& kernel,
		base::parallelizer&,
		base::execution_params&
	) override;
};

} // namespace ecs
} // namespace eagine

#include <eagine/ecs/storage/posix_fs.inl>

#endif //include guard

